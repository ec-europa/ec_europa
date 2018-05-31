<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_site_header() {
  return array(
    'site_header' => array(
      'template' => 'site-header',
      'variables' => array(
        'site_switcher' => array(
          '#theme' => _atomium_extend_theme_hook('site_switcher'),
          '#attributes' => array(
            'class' => array('ecl-site-switcher--header'),
          ),
        ),
        'logo' => array(
          '#theme' => _atomium_extend_theme_hook('logo'),
          '#title' => t('Home - European Commission'),
          '#attributes' => array(
            'class' => array('ecl-site-header__logo', 'ecl-logo'),
          ),
        ),
        'lang_select_site' => array(
          '#theme' => _atomium_extend_theme_hook('lang_select_site'),
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__lang-select-sites',
            ),
          ),
        ),
        'search_bar' => array(
          '#theme' => _atomium_extend_theme_hook('search_bar'),
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__search',
            ),
          ),
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
  $variables['menu'] = _atomium_block_get_render_array('system', 'user-menu');

  // There is a bigger probability that visited pages would not be the homepage.
  // So, instead of using a negative condition (!drupal_is_front_page()),
  // I check only when we are on frontpage.
  // We'll gain a bit of performance here.
  if (drupal_is_front_page()) {
    $variables['logo']['#attributes'] = $variables['atomium']['attributes']['logo']
      ->setAttributes($variables['logo']['#attributes'])
      ->replace('class', 'ecl-logo', 'ecl-logo--logotype')
      ->toArray();
  }
}
