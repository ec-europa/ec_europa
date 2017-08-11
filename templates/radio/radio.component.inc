<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_radio() {
  return array(
    'label' => 'Radio',
    'description' => 'Radio.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_radio($form, &$form_state) {
  $form['element1'] = array(
    '#title' => 'Default',
    '#type' => 'radio',
  );

  $form['element2'] = array(
    '#title' => 'Checked option',
    '#type' => 'radio',
    '#attributes' => array(
      'checked',
    ),
  );

  $form['element3'] = array(
    '#title' => 'Disabled option',
    '#type' => 'radio',
    '#disabled' => TRUE,
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radio(&$variables, $hook) {
  $classes = array('ecl-radio__input', 'ecl-sr-only');
  _ec_europa_form_set_css_class($variables, $classes);
}
