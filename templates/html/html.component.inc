<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_html(&$variables, $hook) {
  $this_theme_path = drupal_get_path('theme', 'ec_europa');
  $variables['theme_path'] = $this_theme_path;
  $language = $variables['language'];

  if (isset($language->prefix)) {
    $variables['atomium']['attributes']['body']->append('class', 'language-' . $language->prefix);
  }

  // For some reason, the front page handles tokens different.
  if (drupal_is_front_page()) {
    $data = ['node' => menu_get_object('node')];
    $last_modified = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'last-modified',
        'content' => token_replace('[dt_tokens:dt_update_date]', $data),
      ),
    );
    drupal_add_html_head($last_modified, 'last_modified');
  }

  // Override splash screen title.
  $menu_item = menu_get_item();
  if (isset($menu_item['path']) && $menu_item['path'] == 'splash' && !variable_get('splash_screen_title_value', FALSE)) {
    $site_name = variable_get('site_name');
    $variables['head_title'] = $site_name;
    drupal_set_title($site_name);
  }
}
