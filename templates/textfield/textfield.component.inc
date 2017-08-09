<?php

/**
 * @file
 * Contains texfield component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_textfield(&$variables, $hook) {
  // Add necessary CSS classes like "error" class on validation error.
  $classes = array(
    'default' => array('ecl-text-input'),
  );
  _ec_europa_form_set_css_class($variables, $classes);
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
  $classes = array(
    'default' => array('ecl-search-form__textfield'),
  );
  _ec_europa_form_set_css_class($variables, $classes);
  $variables['attributes_array']['size'] = 30;
}
