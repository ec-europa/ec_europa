<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_labels() {
  return array(
    'labels' => array(
      'template' => 'field__list_boolean__node__full__community',
      'variables' => array(
        'markup' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_labels() {
  return array(
    'label' => 'Labels',
    'description' => 'Labels for status in community profile. (used in community access field)',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_labels($form, &$form_state) {
  $form['element1'] = array(
    '#markup' => 'Example Open Status',
  );
  $form['#attributes']['class'][] = array('ecl-label', 'ecl-label--open');
  return $form;
}
