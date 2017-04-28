<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function europa_atomium_theme_grid() {
  return array(
    'grid' => array(
      'variables' => array(
        'rows' => NULL,
      ),
      'template' => 'grid',
    ),
  );
}

/**
 * Implements hook_atomium_definition_HOOK().
 */
function europa_atomium_definition_grid() {
  return array(
    'label' => 'Grid',
    'description' => 'Banner.',
    'preview' => array(
      'rows' => array(
        '0' => 'Nullam eget gravida sapien. Curabitur nec ligula varius tellus blandit auctor in non felis.',
        '1' => 'Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Pellentesque in volutpat eros, ut fringilla tortor.'
      ),
    ),
  );
}
