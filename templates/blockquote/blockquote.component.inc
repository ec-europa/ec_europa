<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_blockquote(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-blockquote';
}
