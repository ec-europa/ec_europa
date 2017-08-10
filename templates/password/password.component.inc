<?php

/**
 * @file
 * Contains password component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_password() {
  return array(
    'label' => 'Password field',
    'description' => 'Default password field.',
    'preview' => array(
      'element1' => array(
        'title' => 'Password field',
        'description' => 'Description',
        'attributes' => array(
          'size' => 30,
        ),
      ),
      'element2' => array(
        'title' => 'Password field with error.',
        'description' => 'Description',
        'attributes' => array(
          'size' => 30,
          'class' => array(
            'ecl-text-input--has-error',
          ),
        ),
      ),
      'element3' => array(
        'title' => 'Disabled password field.',
        'description' => 'Description',
        'attributes' => array(
          0 => 'disabled',
          'size' => 30,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_password(&$variables, $hook) {
  $classes = array('ecl-text-input');
  $error_classes = array('ecl-text-input--has-error');
  _ec_europa_form_set_css_class($variables, $classes, $error_classes);
}
