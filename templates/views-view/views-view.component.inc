<?php

/**
 * @file
 * Contains component file.
 */
/**
 * Implements hook_preprocess_views_view_grid().
 */
function europa_preprocess_views_view_grid(&$variables) {
  $variables['theme_hook_suggestions'][] =  'grid';
}

/**
 * Implements hook_preprocess_views_view_table().
 */
function europa_preprocess_views_view_table(&$variables) {
  $variables['classes_array'][] = 'table-responsive';
}
