<?php

/**
 * @file
 * js.inc
 */

/**
 * Implements hook_js_alter().
 */
function europa_js_alter(&$js) {
  $base_theme_path = drupal_get_path('theme', 'bootstrap');
  $path_fancybox = libraries_get_path('fancybox');

  unset(
    $js[$base_theme_path . '/js/misc/ajax.js'],
    $js[$path_fancybox . '/jquery.fancybox.pack.js'],
    $js[$path_fancybox . '/helpers/jquery.fancybox-thumbs.js'],
    $js[$path_fancybox . '/helpers/jquery.fancybox-buttons.js'],
    $js[$path_fancybox . '/helpers/jquery.fancybox-media.js'],
    $js['profiles/multisite_drupal_standard/themes/bootstrap/js/bootstrap.js']
  );
}
