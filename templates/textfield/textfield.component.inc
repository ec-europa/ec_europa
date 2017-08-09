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
  _ec_europa_form_set_css_class($element, array('ecl-text-input'));

  // Atomium does not support preprocess on "textfield" variant yet.
  // Waiting for this fix, we are obliged to pass by this workaround.
  _ec_europa_preprocess_textfield__nexteuropa_europa_search_search_form__query_text($variables, $hook);
}

/**
 * Implements textfield specificity of the QueryText fields.
 *
 * It is related to the "search_bar" component based on Europa search
 * simple form.
 *
 * @see ec_europa_preprocess_textfield();
 */
function _ec_europa_preprocess_textfield__nexteuropa_europa_search_search_form__query_text(&$variables, $hook) {
  $element = &$variables['element'];
  if ($element['#id'] == 'edit-querytext') {
    $variables['attributes_array']['class'][] = 'ecl-search-form__textfield';
    $variables['attributes_array']['size'] = 30;
  }
}
