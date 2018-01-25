<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_maintenance_page(&$variables, $hook) {
  $variables['theme_path'] = drupal_get_path('theme', 'ec_europa');
  $variables['front_page'] = url('<front>');
  $variables['content_column_class'] = 'ecl-col-12';
  $variables['page_logo_title'] = t('Home - @sitename', ['@sitename' => variable_get('site_name', 'European Commission')]);
  $variables['site_header'] = array(
    '#theme' => _atomium_extend_theme_hook('site_header', $variables['theme_hook_original']),
  );

  $variables['messages'] = NULL;
  if ($variables['show_messages']) {
    $variables['messages'] = array(
      '#theme' => _atomium_extend_theme_hook('status_messages', $variables['theme_hook_original']),
    );
  }

  $language = $GLOBALS['language'];
  $language->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

  $variables['page_header'] = array(
    '#theme' => _atomium_extend_theme_hook('page_header', $variables['theme_hook_original']),
    '#identity' => $variables['site_name'],
    '#title_prefix' => $variables['title_prefix'],
    '#title_suffix' => $variables['title_suffix'],
    '#title' => drupal_get_title(),
  );

  $variables['atomium']['attributes']['html']
    ->append('class', 'no-js')
    ->append('lang', $language->language)
    ->append('dir', $language->dir)
    ->delete('prefix');

  $variables['atomium']['attributes']['head']
    ->append('profile', 'http://www.w3.org/1999/xhtml/vocab');

  $variables['footer'] = array(
    '#theme' => _atomium_extend_theme_hook('footer', $variables['theme_hook_original']),
  );
}
