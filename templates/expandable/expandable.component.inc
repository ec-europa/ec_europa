<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_expandable() {
  return array(
    'expandable' => array(
      'variables' => array(
        'title' => NULL,
        'body' => NULL,
        'id' => NULL,
        'link' => array(),
      ),
      'template' => 'expandable',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_expandable() {
  return array(
    'label' => 'Expandable',
    'description' => 'Expandable.',
    'preview' => array(
      'title' => 'Expandable link',
      'body' => '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit</p>',
      'id' => 'example-expandable',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_expandable(&$variables, $hook) {
  $variables['link'] = array(
    '#theme' => array('link'),
    '#text' => $variables['title'],
    '#path' => '#',
    '#attributes_array' => array(
      'id' => $variables['id'] . '-button',
      'class' => array(
        'ecl-expandable__button',
        'ecl-link',
      ),
      'aria-controls' => $variables['id'],
      'aria-expanded' => 'false',
    ),
  );
}
