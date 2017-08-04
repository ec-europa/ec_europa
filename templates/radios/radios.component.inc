<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radios(&$variables) {
  $variables['attributes_array']['class'][] = 'ecl-radio-group';
  $variables['attributes_array']['role'][] = 'radiogroup';
}
