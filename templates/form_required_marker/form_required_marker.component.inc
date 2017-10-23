<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_required_marker(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'text-danger');
}
