<?php

/**
 * @file
 * css.inc
 */

/**
 * Implements hook_css_alter().
 */
function ec_europa_css_alter(&$css) {
  if (function_exists('libraries_get_path') && ($path_fancybox = libraries_get_path('fancybox'))) {
    unset(
      $css[$path_fancybox . '/helpers/jquery.fancybox-buttons.css'],
      $css[$path_fancybox . '/helpers/jquery.fancybox-thumbs.css'],
      $css[$path_fancybox . '/jquery.fancybox.css']
    );
  }
  if (function_exists('drupal_get_path') && ($path_date_api = drupal_get_path('module', 'date'))) {
    unset(
      $css[$path_date_api . '/date_api/date.css']
    );
  }
}
