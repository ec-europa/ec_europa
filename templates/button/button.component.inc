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
    'Default' => 'ecl-button--default',
    'Primary' => 'ecl-button--primary',
    'Secondary' => 'ecl-button--secondary',
    'Call to action' => 'ecl-button--call ecl-button--caret-right',
    'Icon: Caret down' => 'ecl-button--default ecl-button--caret-down',
    'Icon: Caret up' => 'ecl-button--default ecl-button--caret-up',
    'Icon: Caret right' => 'ecl-button--default ecl-button--caret-right',
    'Icon: Caret left' => 'ecl-button--default ecl-button--caret-left',
    'Primary button, block-wide, with caret-down' => 'ecl-button--primary ecl-button--block ecl-button--caret-down',
  );

  foreach ($variants as $value => $classes) {
    $form['buttons'][] = array(
      '#theme' => 'button',
      '#button_type' => 'button',
      '#title' => $value,
      '#value' => $value,
      '#attributes' => array(
        'class' => array(
          $classes,
        ),
      ),
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

  if (_ec_europa_array_find('ecl-button--', $variables['attributes_array']['class']) === FALSE) {
    $variables['attributes_array']['class'][] = 'ecl-button--default';
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__primary(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--primary',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__secondary(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--secondary',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__call(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--call',
    'ecl-button--caret-right',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__timeline(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--call',
    'ecl-button--caret-down',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__caret_up(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--default',
    'ecl-button--caret-up',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__caret_right(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--default',
    'ecl-button--caret-right',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__caret_down(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--default',
    'ecl-button--caret-down',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__caret_left(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--default',
    'ecl-button--caret_left',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__primary_block(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button--primary',
    'ecl-button--block',
    'ecl-button--caret-down',
  );
}
