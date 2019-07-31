<?php

/**
 * @file
 * Ds_layouts for europa theme implementation.
 */

/**
 * Implement NE 1 col layout.
 */
function ds_ne_1col() {
  return array(
    'label' => \t('NE: 1col'),
    'regions' => array(
      'main' => \t('Main'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
    // Add this line if you're using DS 2.x for icon preview.
    'image' => TRUE,
  );
}
