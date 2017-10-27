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
        'logo' => array(
          '#theme' => array('logo'),
          '#title' => t('Home - European Commission'),
          '#attributes' => array(
            'class' => array('ecl-site-header__logo', 'ecl-logo--logotype'),
          ),
        ),
        'lang_select_site' => array(
          '#theme' => array('lang_select_site'),
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__lang-select-sites',
            ),
          ),
        ),
        'search_bar' => array(
          '#theme' => array('search_bar'),
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
