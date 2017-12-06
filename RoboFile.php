<?php

use Robo\Tasks;

/**
 * Class RoboFile.
 */
class RoboFile extends Tasks {

  use NuvoleWeb\Robo\Task\Config\loadTasks;

  /**
   * Setup project.
   *
   * This command will create the necessary symlinks and scaffolding files.
   *
   * @command project:setup
   * @aliases ps
   */
  public function projectSetup() {

    $config = [
      $this->taskFilesystemStack()->chmod($this->getSiteRoot() . '/sites', 0775, 0000, TRUE),
      $this->taskWriteConfiguration($this->getSiteRoot() . '/sites/default/drushrc.php')->setConfigKey('drush'),
      $this->taskAppendConfiguration($this->getSiteRoot() . '/sites/default/default.settings.php')->setConfigKey('settings'),
    ];

    if ('drupal-module' === $this->getProjectType()) {
      $path = '/sites/all/modules/' . $this->getProjectName();
    }

    if ('drupal-theme' === $this->getProjectType()) {
      $path = '/sites/all/themes/' . $this->getProjectName();
    }

    $config[] = $this->taskFilesystemStack()->symlink($this->getProjectRoot(), $this->getSiteRoot() . $path);

    $collection = $this->collectionBuilder()->addTaskList($config);

    if (file_exists('behat.yml.dist')) {
      $collection->addTask($this->projectSetupBehat());
    }

    if (file_exists('phpunit.xml.dist')) {
      $collection->addTask($this->projectSetupPhpUnit());
    }

    return $collection;
  }

  /**
   * Setup PHPUnit.
   *
   * This command will copy phpunit.xml.dist in phpunit.xml and replace
   * configuration tokens with values provided in robo.yml.dist / robo.yml.
   *
   * For example, given the following configuration:
   *
   * > site:
   * >   root: build
   *
   * Then its token format would be: !site.root
   *
   * @command project:setup-phpunit
   * @aliases psp
   *
   * @return \Robo\Collection\CollectionBuilder
   *   Collection builder.
   */
  public function projectSetupPhpUnit() {
    return $this->getReplaceConfigurationTokensTasks('phpunit.xml.dist', 'phpunit.xml');
  }

  /**
   * Setup Behat.
   *
   * This command will copy phpunit.xml.dist in phpunit.xml and replace
   * configuration tokens with values provided in robo.yml.dist / robo.yml.
   *
   * For example, given the following configuration:
   *
   * > site:
   * >   root: build
   *
   * Then its token format would be: !site.root
   *
   * @command project:setup-behat
   * @aliases psb
   *
   * @return \Robo\Collection\CollectionBuilder
   *   Collection builder.
   */
  public function projectSetupBehat() {
    return $this->getReplaceConfigurationTokensTasks('behat.yml.dist', 'behat.yml');
  }

  /**
   * Install target site.
   *
   * This command will install the target site using configuration values
   * provided in robo.yml.dist (overridable by robo.yml).
   *
   * @command project:install
   * @aliases pi
   */
  public function projectInstall() {
    return $this->collectionBuilder()->addTaskList([
      $this->getInstallTask()->arg($this->config('site.profile')),
      $this->getDrush()->arg('en')->args($this->config('modules.enable')),
      $this->getDrush()->arg('dis')->args($this->config('modules.disable')),
    ]);
  }

  /**
   * Get installation task.
   *
   * @return \Robo\Task\Base\Exec
   *   Drush installation task.
   */
  protected function getInstallTask() {
    return $this->getDrush()
      ->options([
        'site-name' => $this->config('site.name'),
        'site-mail' => $this->config('site.mail'),
        'locale' => $this->config('site.locale'),
        'account-mail' => $this->config('account.mail'),
        'account-name' => $this->config('account.name'),
        'account-pass' => $this->config('account.password'),
        'db-prefix' => $this->config('database.prefix'),
        'exclude' => $this->config('site.root'),
        'db-url' => sprintf("mysql://%s:%s@%s:%s/%s",
          $this->config('database.user'),
          $this->config('database.password'),
          $this->config('database.host'),
          $this->config('database.port'),
          $this->config('database.name')),
      ], '=')
      ->arg('site-install');
  }

  /**
   * Get configured Drush task.
   *
   * @return \Robo\Task\Base\Exec
   *   Exec command.
   */
  protected function getDrush() {
    return $this->taskExec($this->config('bin.drush'))
      ->option('-y')
      ->option('root', $this->getSiteRoot(), '=');
  }

  /**
   * Get root directory.
   *
   * @return string
   *   Root directory.
   */
  protected function getProjectRoot() {
    return getcwd();
  }

  /**
   * Get site root directory.
   *
   * @return string
   *   Root directory.
   */
  protected function getSiteRoot() {
    return $this->getProjectRoot() . '/' . $this->config('site.root');
  }

  /**
   * Get project name from composer.json.
   *
   * @return string
   *   Project name.
   */
  protected function getProjectName() {
    $package = json_decode(file_get_contents('./composer.json'));
    list(, $name) = explode('/', $package->name);
    return $name;
  }

  /**
   * Get project type from composer.json.
   *
   * @return string
   *   Project name.
   */
  protected function getProjectType() {
    $package = json_decode(file_get_contents('./composer.json'));

    return $package->type;
  }

  /**
   * Replace configuration tokens in files.
   *
   * @param string $source
   *   Source file.
   * @param string $destination
   *   Destination file.
   *
   * @return \Robo\Collection\CollectionBuilder
   *   Collection builder.
   */
  protected function getReplaceConfigurationTokensTasks($source, $destination) {
    $tokens = $this->parseTokens($source);
    $configuration = $this->getConfigurationFromTokens($tokens);
    return $this->collectionBuilder()->addTaskList([
      $this->taskFilesystemStack()->copy($source, $destination, TRUE),
      $this->taskReplaceInFile($destination)->from('!site.root')->to($this->getSiteRoot()),
      $this->taskReplaceInFile($destination)->from($tokens)->to($configuration),
    ]);
  }

  /**
   * Parse a file and extract its tokens.
   *
   * @param string $file
   *   Path to file.
   *
   * @return array
   *   List of tokens.
   */
  protected function parseTokens($file) {
    preg_match_all('/!((\w+\.?)+)/', file_get_contents($file), $matches);
    if (isset($matches[0]) && !empty($matches[0]) && is_array($matches[0])) {
      return $matches[0];
    }

    return [];
  }

  /**
   * Get configuration values from tokens.
   *
   * @param array $tokens
   *   Token list.
   *
   * @return array
   *   Configuration values.
   */
  protected function getConfigurationFromTokens(array $tokens) {
    foreach ($tokens as $key => $token) {
      $tokens[$key] = $this->config(ltrim($token, '!'));
    }
    return $tokens;
  }

}
