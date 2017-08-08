<?php

/**
 * @file
 * Contains password component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_password(&$variables, $hook) {
  $classes = array(
    'default' => array('ecl-text-input'),
    'error' => array('ecl-text-input--has-error'),
  );
  _ec_europa_form_set_css_class($variables, $classes);
}
