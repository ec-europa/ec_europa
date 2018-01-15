<?php

/**
 * @file
 * js.inc
 */

/**
 * Implements hook_js_alter().
 *
 * @SuppressWarnings(PHPMD)
 */
function ec_europa_js_alter(&$js) {
  if (module_exists('libraries') && ($path_fancybox = libraries_get_path('fancybox'))) {
    unset(
      $js[$path_fancybox . '/jquery.fancybox.pack.js'],
      $js[$path_fancybox . '/helpers/jquery.fancybox-thumbs.js'],
      $js[$path_fancybox . '/helpers/jquery.fancybox-buttons.js'],
      $js[$path_fancybox . '/helpers/jquery.fancybox-media.js']
    );
  }
}
