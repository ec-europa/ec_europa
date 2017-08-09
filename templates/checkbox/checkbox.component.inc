<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_checkbox() {
  return array(
    'label' => 'Checkboxes',
    'description' => 'Default checkboxes.',
    'preview' => array(
      'element1' => array(
        'title' => 'Normal checkbox',
      ),
      'element2' => array(
        'title' => 'Disabled checkbox',
        'attributes' => array(
          'disabled',
        ),
      ),
      'element3' => array(
        'title' => 'Checkbox with error',
      ),
      'element4' => array(
        'title' => 'Checkbox by default',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_checkbox(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-checkbox__input ecl-sr-only';
}
