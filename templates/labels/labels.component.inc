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
      'template' => 'labels',
      'variables' => array(
        'status' => NULL,
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
    'description' => 'Labels.',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_labels($form, &$form_state) {
  $form['element1'] = [
    '#theme' => 'labels',
    '#status' => 'upcoming',
  ];

  $form['element2'] = [
    '#theme' => 'labels',
    '#status' => 'open',
  ];

  $form['element3'] = [
    '#theme' => 'labels',
    '#status' => 'close',
  ];
  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-label';
  $variables['attributes_array']['class'][] = 'ecl-label--' . $variables['status'];
  $variables['title'] = t('Call status: @state', array('@state' => $variables['status']));
}
