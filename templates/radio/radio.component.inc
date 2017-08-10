<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radio(&$variables, $hook) {
  $classes = array('ecl-radio__input', 'ecl-sr-only');
  _ec_europa_form_set_css_class($variables, $classes);
}
