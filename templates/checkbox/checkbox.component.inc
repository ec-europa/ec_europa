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
    'description' => 'Checkbox.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_checkbox(array $form, array &$form_state) {
  $form['elements'][] = array(
    '#type' => 'checkbox',
    '#title' => 'Normal checkbox',
  );
  $form['elements'][] = array(
    '#type' => 'checkbox',
    '#title' => 'Disabled checkbox',
    '#disabled' => TRUE,
  );
  $form['elements'][] = array(
    '#type' => 'checkbox',
    '#title' => 'Checkbox with error',
    '#label_tag_attributes' => array(
      'class' => array('ecl-checkbox--has-error'),
    ),
  );
  $form['elements'][] = array(
    '#type' => 'checkbox',
    '#title' => 'Checked by default',
    '#attributes' => array(
      'checked' => TRUE,
    ),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_checkbox(array &$variables, $hook) {
  $classes = array('ecl-checkbox__input', 'ecl-u-sr-only');
  _ec_europa_form_set_css_class($variables, $classes);
}
