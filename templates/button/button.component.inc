<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_HOOK().
 */
function europa_atomium_definition_button() {
  return array(
    'label' => 'Button',
    'description' => 'Button template.',
    'preview' => array(
      array(
        'type' => 'submit',
        'value' => 'Default',
        'attributes' => array(
          'class' => array(
            'btn-default',
          ),
        ),
      ),
      array(
        'type' => 'submit',
        'value' => 'Primary',
        'attributes' => array(
          'class' => array(
            'btn-primary',
          ),
        ),
      ),
      array(
        'type' => 'submit',
        'value' => 'Secondary',
        'attributes' => array(
          'class' => array(
            'btn-secondary',
          ),
        ),
      ),
      array(
        'type' => 'submit',
        'value' => 'Button with contour',
        'attributes' => array(
          'class' => array(
            'btn-ctn',
          ),
        ),
      ),
      array(
        'type' => 'submit',
        'value' => 'Button with border',
        'attributes' => array(
          'class' => array(
            'btn-ctn--border',
          ),
        ),
      ),
      array(
        'type' => 'submit',
        'value' => 'Button for menus',
        'attributes' => array(
          'class' => array(
            'btn-menu',
          ),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function europa_preprocess_button(&$variables) {
  $variables['attributes_array']['class'][] = 'btn';
}
