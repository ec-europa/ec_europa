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
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_checkboxes($form, &$form_state) {
  $form['element1'] = array(
    '#title' => 'Checkboxes component',
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
function ec_europa_preprocess_checkboxes(&$variables, $hook) {
  $element = $variables['element'];

  $variables['attributes_array']['class'][] = 'ecl-checkbox-group';
  $variables['attributes_array']['role'][] = 'checkboxgroup';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    $variables['attributes_array']['aria-labelledby'][] = $title;

    $variables['small_description'] = t('List of options for @title', array('@title' => $title));

    $descr_attributes_array['class'] = array('ecl-sr-only');
    if (isset($descr_attributes_array['id'])) {
      $descr_attributes_array['id'] = array($element['#id'] . "-description");
    }
    $variables['descr_attributes_array'] = $descr_attributes_array;
  }

  if (!empty($element['#description'])) {
    $variables['description'] = $element['#description'];
  }
}
