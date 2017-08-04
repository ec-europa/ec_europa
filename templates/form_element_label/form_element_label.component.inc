<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element_label(&$variables, $hook) {
  $element = $variables['element'];
  if (isset($variables['element']['element'])) {
    $element = $variables['element']['element'];
  }

  if (!empty($element['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'form_element_label__' . $element['#field_name'];
  }

  if (!empty($element['#type'])) {
    $variables['theme_hook_suggestions'][] = 'form_element_label__' . $element['#type'];
  }
  $variables['attributes_array']['class'][] = 'ecl-form-label';
}
