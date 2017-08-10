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
    'label' => 'Checkbox',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_checkbox($form, &$form_state) {
  $form['element1'] = array(
    '#type' => 'checkbox',
    '#title' => 'Normal checkbox',
  );
  $form['element2'] = array(
    '#type' => 'checkbox',
    '#title' => 'Disabled checkbox',
    '#disabled' => TRUE,
  );
  $form['element3'] = array(
    '#type' => 'checkbox',
    '#title' => 'Checkbox with error',
  );
  $form['element4'] = array(
    '#type' => 'checkbox',
    '#title' => 'Checkbox by default',
  );

  return $form;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_checkbox(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-checkbox__input ecl-sr-only';
}
