<?php

/**
 * @file
 * Contains password component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_password(&$variables, $hook) {
  $classes = array('ecl-text-input');
  $error_classes = array('ecl-text-input--has-error');
  _ec_europa_form_set_css_class($variables, $classes, $error_classes);
}
