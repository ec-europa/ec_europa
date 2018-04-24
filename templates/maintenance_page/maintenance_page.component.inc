<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_maintenance_page(array &$variables, $hook) {
  $variables['theme_path'] = drupal_get_path('theme', 'ec_europa');
  $variables['front_page'] = url('<front>');
  $variables['content_column_class'] = 'ecl-col-12';
  $variables['page_logo_title'] = t('Home - @sitename', array('@sitename' => variable_get('site_name', 'European Commission')));
  $site_header = array(
    '#theme' => 'site_header',
  );

  _atomium_extend_theme_property(
    $site_header,
    array($variables['theme_hook_original'])
  );

  $variables['site_header'] = array(
    '#theme' => $site_header,
  );

  $messages = NULL;
  if ($variables['show_messages']) {
    $messages = array(
      '#theme' => 'status_messages',
    );
    _atomium_extend_theme_property(
      $messages,
      array($variables['theme_hook_original']));
  }
  $variables['messages'] = $messages;

  $language = $GLOBALS['language'];
  $language->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

  $page_header = array(
    '#theme' => 'page_header',
    '#identity' => $variables['site_name'],
    '#title_prefix' => $variables['title_prefix'],
    '#title_suffix' => $variables['title_suffix'],
    '#title' => drupal_get_title(),
  );
  _atomium_extend_theme_property(
    $page_header,
    array($variables['theme_hook_original']));
  $variables['page_header'] = $page_header;

  $variables['atomium']['attributes']['html']
    ->append('class', 'no-js')
    ->append('lang', $language->language)
    ->append('dir', $language->dir)
    ->delete('prefix');

  $variables['atomium']['attributes']['head']
    ->append('profile', 'http://www.w3.org/1999/xhtml/vocab');

  $footer = array(
    '#theme' => 'footer',
  );
  _atomium_extend_theme_property(
    $footer,
    array($variables['theme_hook_original']));
  $variables['footer'] = $footer;
}
