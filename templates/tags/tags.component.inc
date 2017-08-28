<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_form_hook().
 */
/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_tags(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-tag';
  foreach ($variables['items'] as &$item) {
    $item['#options']['attributes']['class'][] = 'ecl-tag__item';
  }
}
