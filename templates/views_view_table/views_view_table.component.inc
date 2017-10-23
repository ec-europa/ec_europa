<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_views_view_table(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-table', 'table-responsive'));
}
