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
function ec_europa_atomium_definition_form_textarea(array $form, array &$form_state) {
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
function ec_europa_preprocess_textarea(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->merge($variables['element']['#attributes']);
  $variables['atomium']['attributes']['element']->append('class', 'ecl-textarea');
  $variables['atomium']['attributes']['element']->setAttribute('role', 'textbox');
  $variables['atomium']['attributes']['element']->setAttribute('aria-multiline', 'true');
  $variables['atomium']['attributes']['element']->setAttribute('aria-labelledby', $variables['element']['#id'] . '_label');
  $variables['element']['#value'] = \check_plain($variables['element']['#value']);
}
