<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_page_header() {
  return array(
    'page_header' => array(
      'variables' => array(
        'identity' => NULL,
        'title' => NULL,
        'introduction' => NULL,
        'meta' => NULL,
        'breadcrumb' => NULL,
      ),
      'template' => 'page-header',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_page_header() {
  return array(
    'label' => 'Page header',
    'description' => 'Page header.',
    'preview' => array(
      'identity' => 'Digital single market',
      'title' => 'Business, Economy, Euro',
      'introduction' => 'EU economy, finance and the euro, and practical information for EU businesses and entrepreneurs on product safety, environmental regulations, trade with non-EU countries and competition rules.',
      'meta' => array(
        '#theme' => _atomium_extend_theme_hook('meta'),
        '#type' => 'News article',
        '#timestamp' => '2015-07-06T17:44:28+02:00',
        '#date' => '6 July 2015',
        '#location'  => 'Brussels',
        '#attributes'  => array(
          'class' => array(
            'ecl-meta--header',
          ),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_page_header(&$variables, $hook) {
  if (module_exists('easy_breadcrumb')) {
    // @TODO: The file includes/easy_breadcrumb.blocks.inc
    // @TODO: only exists in easy_breadcrumb <= 7.x-2.12
    // @TODO: Please refactor when upgrading easy_breadcrumb.
    module_load_include('inc', 'easy_breadcrumb', 'includes/easy_breadcrumb.blocks');
    $variables['breadcrumb'] = _easy_breadcrumb_block();
  }
}
