<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_blockquote() {
  return array(
    'label' => 'Blockquote',
    'description' => 'Blockquote.',
    'preview' => array(
      'body' => 'Blockquote body.',
      'author' => 'Blockquote author.',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_blockquote(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-blockquote';
}
