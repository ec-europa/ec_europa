<?php

/**
 * @file
 * Contains password component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_password() {
  return array(
    'label' => 'Password field',
    'description' => 'Password field.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_password(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Normal password.',
    '#type' => 'password',
    '#description' => t('Description'),
  );

  $form['element2'] = array(
    '#title' => 'Disabled password.',
    '#type' => 'password',
    '#description' => t('Description'),
    '#disabled' => TRUE,
  );

  $form['element3'] = array(
    '#title' => 'Password with error.',
    '#type' => 'password',
    '#description' => t('Description'),
    '#attributes' => array(
      'class' => array(
        'ecl-text-input--has-error',
      ),
    ),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_password(array &$variables, $hook) {
  $classes = array('ecl-text-input');
  $error_classes = array('ecl-text-input--has-error');
  _ec_europa_form_set_css_class($variables, $classes, $error_classes);
}
