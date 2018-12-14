<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_item_list__links__comment(array &$variables, $hook) {
  \array_walk($variables['items'], function (&$link) {
    $link['link']['#text'] = drupal_ucfirst($link['link']['#text']);

    $link['link']['#options']['attributes']['class'] = \array_diff(
      $link['link']['#options']['attributes']['class'],
      array('ecl-link--standalone')
    );
  });
}
