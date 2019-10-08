<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_node(array &$variables, $hook) {
  // Add information about the number of sidebars.
  if (!empty($variables['left']) && !empty($variables['right'])) {
    $variables['content_column_class'] = 'ecl-col-md-6';
  }
  elseif (!empty($variables['left']) || !empty($variables['right'])) {
    $variables['content_column_class'] = 'ecl-col-md-9';
  }
  else {
    $variables['content_column_class'] = 'ecl-col-md-12';
  }
  $variables['site_name'] = variable_get('site_name');
  $variables['submitted'] = '';

  if (theme_get_setting('display_submitted')) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array(
      '!username' => $variables['name'],
      '!datetime' => $variables['date'],
    ));
  }

  // Override node_url if Legacy Link is set.
  if (isset($variables['legacy'])) {
    $variables['node_url'] = $variables['legacy'];
  }
  // We have our custom element to add comments.
  if (!empty($variables['content']['links']['comment']['#links'])) {
    unset($variables['content']['links']['comment']['#links']['comment-add']);
  }

  // Add the language attribute.
  if (module_exists('entity_translation')) {
    $variables['atomium']['attributes']['wrapper']->append('lang', entity_translation_get_existing_language('node', $variables['node']));
  }
}
