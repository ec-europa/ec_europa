<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_atomium_overview(array &$variables, $hook) {
  usort($variables['definitions'], function (array $a, array $b) {
    return strcmp($a['label'], $b['label']);
  });
}
