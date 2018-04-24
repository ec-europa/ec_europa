<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_views_mini_pager(array $existing, $type, $theme, $path) {
  return array(
    'views_mini_pager' => array(
      'variables' => array(
        'tags' => array(),
        'element' => 0,
        'parameters' => array(),
        'quantity' => 1,
        // This is only for hook_atomium_definition_hook().
        'pager_page_array' => NULL,
        'pager_total' => NULL,
      ),
      'template' => 'views-mini-pager',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_views_mini_pager(array &$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    '#theme' => 'pager',
    '#quantity' => 1,
  );

  _atomium_extend_theme_property(
    $variables[$variables['base_hook']],
    array($variables['theme_hook_original'])
  );
}
