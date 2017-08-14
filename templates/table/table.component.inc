<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_table() {
  return array(
    'label' => 'Tables',
    'description' => 'Tables.',
    'preview' => array(
      'header' => array(
        array('header 1.1', 'header 1.2', 'header cell 1.3'),
        array('header 2.1', 'header 2.2', 'header cell 2.3'),
      ),
      'rows' => array(
        array('body 1.1', 'body 1.2', 'body cell 1.3'),
        array('body 2.1', 'body 2.2', 'body cell 2.3'),
        array('body 3.1', 'body 3.2', 'body cell 3.3'),
        array('body 4.1', 'body 4.2', 'body cell 4.3'),
      ),
      'footer' => array(
        array('footer 1.1', 'footer 1.2', 'footer cell 1.3'),
        array('footer 2.1', 'footer 2.2', 'footer cell 2.3'),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_table(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-table';
}
