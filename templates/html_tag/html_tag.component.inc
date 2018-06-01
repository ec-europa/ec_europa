<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_html_tag(array &$variables, $hook) {
  $headers = array('h1', 'h2', 'h3', 'h4', 'h5');
  // TODO: Should we keep this ? Can't we just provide this by default ?
  if (in_array($variables['element']['#tag'], $headers)) {
    $variables['atomium']['attributes']['element']
      ->append(
        'class',
        array('ecl-heading', 'ecl-heading--' . $variables['element']['#tag'],
        )
      );
  }
}
