<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_html(array &$variables, $hook) {
  $variables['theme_path'] = drupal_get_path('theme', 'ec_europa');

  if ($language = $variables['language']) {
    $variables['atomium']['attributes']['body']
      ->append('class', 'language-' . $language->prefix);
  }

  // Override splash screen title.
  $menu_item = menu_get_item();
  if (isset($menu_item['path']) && $menu_item['path'] == 'splash' && !variable_get('splash_screen_title_value', FALSE)) {
    $site_name = variable_get('site_name');
    $variables['head_title'] = $site_name;
    drupal_set_title($site_name);
  }

  $variables['atomium']['attributes']['html']
    ->append('class', 'no-js')
    ->append('lang', $language->language)
    ->append('dir', $language->dir)
    ->delete('prefix');

  $variables['atomium']['attributes']['head']
    ->append('profile', $variables['grddl_profile']);
}
