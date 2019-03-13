<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_meta(array $existing, $type, $theme, $path) {
  return array(
    'meta' => array(
      'variables' => array(
        'type' => NULL,
        'timestamp' => NULL,
        'date' => NULL,
        'location'  => NULL,
      ),
      'template' => 'meta',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_meta() {
  return array(
    'label' => 'Meta',
    'description' => 'Meta.',
    'preview' => array(
      'type' => 'News article',
      'timestamp' => '2015-07-06T17:44:28+02:00',
      'date' => '6 July 2015',
      'location'  => 'Brussels',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_meta(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-meta');
}
