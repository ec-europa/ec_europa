<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_site_slogan() {
  return array(
    'site_slogan' => array(
      'variables' => array(
        'markup' => NULL,
      ),
      'template' => 'site-slogan',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_site_slogan() {
  return array(
    'label' => 'Site slogan',
    'description' => 'Site slogan.',
    'preview' => array(
      'markup' => 'European Union because simple is better!',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_site_slogan(&$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#markup' => $variables['markup'],
    ),
  );
}
