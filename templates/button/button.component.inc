<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_button() {
  return array(
    'label' => 'Button',
    'description' => 'Button template.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_button($form, &$form_state) {
  $variants = array(
    'Default' => 'default',
    'Primary' => 'primary',
    'Secondary' => 'secondary',
    'Call to action' => 'call',
  );

  foreach ($variants as $value => $variant) {
    $form['buttons'][] = array(
      '#theme' => array('button__' . $variant),
      '#button_type' => 'button',
      '#title' => $value,
      '#value' => $value,
      '#theme_wrappers' => array('form_element'),
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button(&$variables, $hook) {
  if (empty($variables['attributes_array']['class'])) {
    $variables['attributes_array']['class'] = array();
  }
  array_unshift($variables['attributes_array']['class'], 'ecl-button');

  $variables['attributes_array']['class'][] = 'ecl-button';

  if (_ec_europa_array_find('ecl-button--', $variables['attributes_array']['class']) === FALSE) {
    $variables['attributes_array']['class'][] = 'ecl-button--default';
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__primary(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-button--primary';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__secondary(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-button--secondary';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__call(&$variables, $hook) {
  $variables['attributes_array']['class'][] = array(
    'ecl-button--call',
    'ecl-button--caret-right',
  );
}
