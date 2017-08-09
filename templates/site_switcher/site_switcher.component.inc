<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_site_switcher() {
  return array(
    'site_switcher' => array(
      'template' => 'site-switcher',
      'variables' => array(
        'link_1' => array(
          'title' => NULL,
          'url' => NULL,
          'selected' => NULL,
        ),
        'link_2' => array(
          'title' => NULL,
          'url' => NULL,
          'selected' => NULL,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_site_switcher() {
  return array(
    'label' => 'Site Switcher',
    'description' => 'Site Switcher.',
    'preview' => array(),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_site_switcher(&$variables, $hook) {
  global $language;

  $variables['attributes_array']['class'][] = 'ecl-site-switcher';

  $is_improved_website = (bool) theme_get_setting('ec_europa_improved_website', 'ec_europa');

  $variables['link_1']['title'] = t('Commission and its priorities');
  $variables['link_1']['url'] = 'https://ec.europa.eu/commission/index_' . $language->language;
  $variables['link_1']['selected'] = !$is_improved_website;

  $variables['link_2']['title'] = t('Policies, information and services');
  $variables['link_2']['url'] = 'https://ec.europa.eu/info/index_' . $language->language;
  $variables['link_2']['selected'] = $is_improved_website;
}
