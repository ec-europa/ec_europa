<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_textarea() {
  return array(
    'label' => 'Textarea',
    'description' => 'Textarea.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_textarea($form, &$form_state) {
  $form['element1'] = array(
    '#title' => 'Normal textarea',
    '#type' => 'textarea',
    '#placeholder' => 'Some placeholder text',
  );
  $form['element2'] = array(
    '#title' => 'Disabled textarea',
    '#type' => 'textarea',
    '#placeholder' => 'Some placeholder text',
    '#disabled' => TRUE,
  );
  $form['element3'] = array(
    '#title' => 'Textarea with error',
    '#type' => 'textarea',
    '#placeholder' => 'Some placeholder text',
    '#attributes' => array(
      'class' => array(
        'ecl-textarea--has-error',
      ),
    ),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_textarea(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-textarea';
  $variables['attributes_array']['role'] = 'textbox';
  $variables['attributes_array']['aria-multiline'] = 'true';
  $variables['attributes_array']['aria-labelledby'] = $variables['attributes_array']['id'] . '_label';
}
