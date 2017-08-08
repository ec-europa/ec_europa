<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radios(&$variables, $hook) {
  $element = $variables['element'];
  $variables['attributes_array']['class'][] = 'ecl-radio-group';
  $variables['attributes_array']['role'][] = 'radiogroup';
  if (!empty($element['#title'])) {
    $variables['attributes_array']['aria-labelledby'][] = $element['#title'];
  }

  if (!empty($element['#description'])) {
    $descr_attributes['class'] = array('ecl-sr-only');
    $descr_attributes['id'] = array($element['#id'] . "-description");
    $variables['descr_attributes'] = atomium_drupal_attributes($descr_attributes);
    $variables['description'] = $element['#description'];
  }
}
