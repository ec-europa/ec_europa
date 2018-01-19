<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_links(&$variables, $hook) {
  // Links can be empty.
  if (empty($variables['links'])) {
    return;
  }

  foreach ($variables['links']['links']['#items'] as &$link) {
    $link['link']['#options']['attributes']['class'][] = 'ecl-link';
    $link['link']['#options']['attributes']['class'][] = 'ecl-link--standalone';
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_item_list__links__comment(&$variables, $hook) {
  array_walk($variables['items'], function (&$link) {
    $link['link']['#text'] = drupal_ucfirst($link['link']['#text']);

    $link['link']['#options']['attributes']['class'] = array_diff(
      $link['link']['#options']['attributes']['class'],
      ['ecl-link--standalone']
    );
  });
}
