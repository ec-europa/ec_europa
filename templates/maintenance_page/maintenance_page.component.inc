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
  $variables['site_header'] = array('#theme' => array('site_header'));
  $variables['messages'] = $variables['show_messages'] ? array('#theme' => array('status_messages')) : '';
  $language = $GLOBALS['language'];
  $language->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

  $variables['page_header'] = array(
    '#theme' => array('page_header'),
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
    '#theme' => array('footer'),
  );
}
