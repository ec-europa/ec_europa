<?php

namespace Drupal\ec_europa\TaskRunner\Commands;

use EC\OpenEuropa\TaskRunner\Commands\BaseCommands;
use Symfony\Component\Console\Input\InputOption;

/**
 * Class VisualRegressionCommands.
 *
 * @package My\Custom\TaskRunner\Commands
 */
class VisualRegressionCommands extends BaseCommands {

  /**
   * Build reference site.
   *
   * @command ec_europa:build-reference
   */
  public function buildReference() {
    $collection = $this->collectionBuilder();
    $directory = $this->getConfig()->get('ec_europa.reference.root');
    $repository = $this->getConfig()->get('ec_europa.repository');

    $collection->addTaskList([
      $this->taskFilesystemStack()->remove($directory),
      $this->taskGitStack()->cloneShallow($repository, $directory),
      $this->taskComposerInstall()->workingDir($directory),
    ]);

    return $collection;
  }

  /**
   * Install reference site.
   *
   * @command ec_europa:install-reference
   */
  public function installReference() {
    return $this->taskExec('./vendor/bin/run dsi --root=tests/reference/build --database-name=reference');
  }

  /**
   * Run BackStop tests.
   *
   * @command ec_europa:backstopjs
   */
  public function runBackstop(array $options = [
    'command' => InputOption::VALUE_REQUIRED,
  ]) {
    $exec = "{$options['command']}";

    $task = $this->taskDockerRun('backstopjs/backstopjs')
      ->exec($exec);
    return $task;
  }

  /**
   * Run server with test site.
   *
   * @command ec_europa:run-test
   */
  public function runTestSite() {
    return $this->taskServer(8888)
      ->host('0.0.0.0')
      ->dir('build');
  }

  /**
   * Run server with reference site.
   *
   * @command ec_europa:run-reference
   */
  public function runReferenceSite() {
    return $this->taskServer(8889)
      ->host('0.0.0.0')
      ->dir('tests/reference/build');
  }

}
