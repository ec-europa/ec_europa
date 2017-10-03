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
        'content' => NULL,
        'attributes_array' => array('class' => array('ecl-label')),
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
    '#theme' => 'labels__upcoming',
    '#content' => 'Label component: Upcoming',
  );
  $form['element2'] = array(
    '#theme' => 'labels__open',
    '#content' => 'Label component: Open',
  );
  $form['element3'] = array(
    '#theme' => 'labels__closed',
    '#content' => 'Label component: Closed',
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels__upcoming(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-label--upcoming';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels__open(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-label--open';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels__closed(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-label--close';
}
