<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_tags() {
  return array(
    'tags' => array(
      'variables' => array(
        'label' => NULL,
        'items' => NULL,
      ),
      'template' => 'tags',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_tags() {
  return array(
    'label' => 'Tags',
    'description' => 'Tags template.',
    'preview' => array(
      'label' => 'My term references',
      'items' => array(
        array(
          '#theme' => 'link__tag',
          '#text' => 'sport',
          '#path' => '#',
        ),
        array(
          '#theme' => 'link__tag',
          '#text' => 'economics',
          '#path' => '#',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_tags(&$variables, $hook) {
  // @todo: For consistency, shouldn't it be: ecl-tags ?
  $variables['attributes_array']['class'][] = 'ecl-tag';
  $variables['title_attributes_array']['class'][] = 'ecl-tag__label';
}
