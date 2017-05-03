<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function europa_preprocess_menu_local_tasks(&$variables, $hook) {
  if (isset($variables['primary']) && !empty($variables['primary'])) {
    $variables['primary']['#attributes']['class'][] = 'nav';
    $variables['primary']['#attributes']['class'][] = 'nav-tabs';
  }
  if (isset($variables['secondary']) && !empty($variables['secondary'])) {
    $variables['secondary']['#attributes']['class'][] = 'nav';
    $variables['secondary']['#attributes']['class'][] = 'nav-pills';
  }
}
