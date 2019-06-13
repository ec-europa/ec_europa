<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_pager_next(array &$variables, $hook) {
  $variables[$variables['base_hook']][$variables['base_hook']]['#text'] = t('Next ›');
}
