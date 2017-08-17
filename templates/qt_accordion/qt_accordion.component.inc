<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_qt_accordion($form, &$form_state) {
  $form['element'] = array(
    '#theme' => 'qt_accordion',
    '#options' => array(
      'attributes' => array(),
    ),
    'divs' => array(
      array(
        '#prefix' => 'Tab 1',
        'content' => array(
          '#markup' => '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit</p>',
        ),
      ),
      array(
        '#prefix' => 'Tab 2',
        'content' => array(
          '#markup' => '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit</p>',
        ),
      ),
      array(
        '#prefix' => 'Tab 3',
        'content' => array(
          '#markup' => '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit</p>',
        ),
      ),
    ),
  );

  return $form;
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_qt_accordion() {
  return array(
    'label' => 'QuickTabs - Accordion',
    'description' => 'QuickTabs - Accordion.',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_qt_accordion(&$variables, $hook) {
  $variables['attributes_array'] = drupal_array_merge_deep($variables['element']['#options']['attributes']);
  $variables['attributes_array']['class'] = array('ecl-container');

  // Create all expandable item.
  $variables['element']['expandables'] = array();

  foreach ($variables['element']['divs'] as $div) {
    if (isset($div['#prefix']) && isset($div['content'])) {
      $variables['element']['expandables'][] = array(
        '#theme' => 'expandable',
        '#title' => strip_tags($div['#prefix']),
        '#body' => $div['content'],
      );
    }
  }

  unset($variables['element']['divs']);
}
