<?php

/**
 * @file
 * css.inc
 */

/**
 * Implements hook_css_alter().
 */
function ec_europa_css_alter(array &$css) {
  if (module_exists('libraries') && ($path_fancybox = libraries_get_path('fancybox'))) {
    unset(
      $css[$path_fancybox . '/helpers/jquery.fancybox-buttons.css'],
      $css[$path_fancybox . '/helpers/jquery.fancybox-thumbs.css'],
      $css[$path_fancybox . '/jquery.fancybox.css']
    );
  }

  if (module_exists('date')) {
    unset($css[drupal_get_path('module', 'date') . '/date_api/date.css']);
  }
}
