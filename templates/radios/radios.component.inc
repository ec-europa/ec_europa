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
