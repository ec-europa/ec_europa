<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_table(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-table');
}
