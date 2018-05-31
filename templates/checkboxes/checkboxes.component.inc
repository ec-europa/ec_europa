<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_checkboxes() {
  return array(
    'label' => 'Checkbox group',
    'description' => 'Checkbox group.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_checkboxes(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Simple example',
    '#type' => 'checkboxes',
    '#options' => array(
      'item1' => 'Item 1',
      'item2' => 'Item 2',
      'item3' => 'Item 3',
    ),
    '#default_value' => array('item2'),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_checkboxes(array &$variables, $hook) {
  $element = $variables['element'];

  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-checkbox-group');
  $variables['atomium']['attributes']['wrapper']->setAttribute('role', 'checkboxgroup');

  $variables['small_description'] = '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    $variables['atomium']['attributes']['wrapper']->setAttribute('aria-labelledby', $title);

    $variables['atomium']['attributes']['description']->append('class', 'ecl-u-sr-only');

    if (isset($element['#id'])) {
      $variables['atomium']['attributes']['description']->setAttribute('id', $element['#id'] . '-description');
    }

    $variables['small_description'] = array(
      '#markup' => t('List of options for @title', array('@title' => $title)),
    );
  }
}
