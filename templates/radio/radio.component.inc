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
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_radio($form, &$form_state) {
  $form['element1'] = array(
    '#title' => 'Radio button.',
    '#type' => 'radio',
  );

  $form['element2'] = array(
    '#title' => 'Checked radio button.',
    '#type' => 'radio',
    '#attributes' => array(
      'checked',
    ),
  );

  $form['element3'] = array(
    '#title' => 'Disabled radio button.',
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
