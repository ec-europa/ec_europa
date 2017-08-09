<?php

/**
 * @file
 * Contains texfield component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_textfield(&$variables, $hook) {
  $element = &$variables['element'];

  // Add necessary CSS classes like "error" class on validation error.
  _ec_europa_form_set_css_class($element, array('ecl-text-input'));

  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $element['#attributes']);
}

/**
 * Implements hook_preprocess_hook().
 *
 * It is related to the "search_bar" component based on Europa search
 * simple form.
 *
 * @see ec_europa_preprocess_textfield();
 */
function ec_europa_preprocess_textfield__nexteuropa_europa_search_search_form__querytext(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-search-form__textfield';
  $variables['attributes_array']['size'] = 30;
}
