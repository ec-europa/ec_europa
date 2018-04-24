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
function ec_europa_atomium_definition_form_button(array $form, array &$form_state) {
  $variants = array(
    'Default' => 'default',
    'Primary' => 'primary',
    'Secondary' => 'secondary',
    'Call to action' => 'call',
    'Form' => 'submit',
    'Tags' => 'tags',
  );

  foreach ($variants as $value => $variant) {
    $button = array(
      '#theme' => 'button',
      '#button_type' => 'button',
      '#title' => $value,
      '#value' => $value,
      '#theme_wrappers' => array('form_element'),
    );

    _atomium_extend_theme_property(
      $button,
      array($variant));

    $form['buttons'][] = $button;
  }

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_button(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', 'ecl-button');
}
