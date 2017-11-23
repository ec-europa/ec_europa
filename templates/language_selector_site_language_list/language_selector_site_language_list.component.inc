<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_language_selector_site_language_list() {
  return array(
    'label' => 'Language selector site language list',
    'description' => 'language_selector_site_language_list.',
    'dependencies' => array('language_selector_site', 'splash_screen'),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_language_selector_site_language_list(&$variables, $hook) {
  $variables[$hook] = array(
    $hook => array(
      '#theme' => 'splash',
      '#show_messages' => FALSE,
    ),
  );
}
