<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_select() {
  return array(
    'label' => 'Select',
    'description' => 'Select.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_select($form, &$form_state) {
  $options = array(
    'item1' => 'Item 1',
    'item2' => 'Item 2',
    'item3' => 'Item 3',
    'item4' => array(
      'item41' => 'Item 4.1',
      'item42' => 'Item 4.2',
      'item43' => 'Item 4.3',
    ),
  );

  $form['element1'] = array(
    '#title' => 'Default select list',
    '#type' => 'select',
    '#description' => 'Description',
    '#options' => $options,
  );

  $form['element2'] = array(
    '#title' => 'Disabled select list',
    '#type' => 'select',
    '#description' => 'Description',
    '#disabled' => TRUE,
    '#options' => $options,
  );

  $form['element3'] = array(
    '#title' => 'Select list with error',
    '#type' => 'select',
    '#description' => 'Description',
    '#attributes' => array(
      'class' => array(
        'ecl-text-input--has-error',
      ),
    ),
    '#options' => $options,
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_select(&$variables, $hook) {
  _ec_europa_form_set_css_class($variables, array('ecl-select'), array('ecl-select--has-error'));
}
