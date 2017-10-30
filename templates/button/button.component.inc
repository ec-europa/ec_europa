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
    'Form' => 'submit',
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
  $variables['atomium']['attributes']['element']['class'][] = 'ecl-button';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button__tags(&$variables, $hook) {
  $variables['attributes_array']['class'][] = array(
    'ecl-button--facet-close',
    'ecl-tag__item',
  );
}
