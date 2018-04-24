<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_logo(array $existing, $type, $theme, $path) {
  return array(
    'logo' => array(
      'template' => 'logo',
      'variables' => array(
        'title' => NULL,
        'type' => NULL,
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_logo() {
  return array(
    'label' => 'Logo',
    'description' => 'Logo.',
    'preview' => array(
      'title' => 'Home - European Commission',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_logo(array &$variables, $hook) {
  $variables['atomium']['attributes']['a']->merge($variables['attributes']);
  $variables['atomium']['attributes']['a']->append('class', 'ecl-logo');
  $variables['atomium']['attributes']['a']->set('href', 'https://ec.europa.eu/info/index');
  $variables['atomium']['attributes']['a']->set('title', $variables['title']);
}
