<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_radios() {
  return array(
    'label' => 'Radio group',
    'description' => 'Radio group.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_radios(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Radios component',
    '#type' => 'radios',
    '#options' => array(
      'item1' => t('Item 1'),
      'item2' => t('Item 2'),
      'item3' => t('Item 3'),
    ),
    '#default_value' => 'item2',
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radios(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-radio-group');
  $variables['atomium']['attributes']['wrapper']->append('role', 'radiogroup');

  $element = $variables['element'];

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    $variables['atomium']['attributes']['wrapper']->append('aria-labelledby', $title);

    $variables['description'] = t('List of options for @title', array('@title' => $title));
    $variables['atomium']['attributes']['description']->append('class', 'ecl-u-sr-only');

    if (isset($element['#id'])) {
      $variables['atomium']['attributes']['description']->append('id', $element['#id'] . '-description');
    }
  }
}
