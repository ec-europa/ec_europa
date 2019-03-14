<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_site_header(array $existing, $type, $theme, $path) {
  return array(
    'site_header' => array(
      'template' => 'site-header',
      'variables' => array(
        'site_switcher' => array(
          '#theme' => 'site_switcher',
          '#attributes' => array(
            'class' => array('ecl-site-switcher--header'),
          ),
        ),
        'logo' => array(
          '#theme' => 'logo',
          '#title' => t('Home - European Commission'),
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__logo',
              'ecl-logo--logotype',
              'ecl-logo',
            ),
          ),
        ),
        'lang_select_site' => array(
          '#theme' => 'lang_select_site',
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__lang-select-sites',
            ),
          ),
        ),
        'search_bar' => array(
          '#theme' => 'search_bar',
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__search',
            ),
          ),
        ),
        'site_slogan' => array(
          '#theme' => 'site_slogan',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_site_header() {
  return array(
    'label' => 'Site Header',
    'description' => 'Site header.',
    'preview' => array(),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_site_header(array &$variables, $hook) {
  $variables['#atomium_recursive'] = TRUE;

  _atomium_extend_theme_property(
    $variables['site_slogan'],
    array($variables['theme_hook_original'])
  );

  $variables['menu'] = _ec_europa_block_get_render_array('system', 'user-menu');
}
