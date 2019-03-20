<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_atomium_overview(array &$variables, $hook) {
  usort(
    $variables['definitions'],
    function ($definition1, $definition2) {
      return strnatcmp($definition1['label'], $definition2['label']);
    }
  );
}
