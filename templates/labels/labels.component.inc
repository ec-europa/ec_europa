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
        'atomium' => array(
          'attributes' => array(
            'wrapper' => array(
              'class' => array('ecl-label'),
            ),
          ),
        ),
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
  $form['elements'][] = array(
    '#theme' => 'labels__upcoming',
    '#content' => 'Label component: Upcoming',
  );
  $form['elements'][] = array(
    '#theme' => 'labels__open',
    '#content' => 'Label component: Open',
  );
  $form['elements'][] = array(
    '#theme' => 'labels__close',
    '#content' => 'Label component: Close',
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels__upcoming(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append(
    'class',
    'ecl-label--upcoming'
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels__open(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append(
    'class',
    'ecl-label--open'
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_labels__close(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append(
    'class',
    'ecl-label--close'
  );
}
