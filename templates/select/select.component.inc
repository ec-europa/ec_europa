<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_select() {
  $options = array(
    'item1' => 'Item 1',
    'item2' => 'Item 2',
    'item3' => 'Item 3',
    'item4' => array(
      'item41' => 'Item 4.1',
      'item42' => 'Item 4.2',
      'item43' => 'Item 4.3',
    ),
  );

  return array(
    'label' => 'Select',
    'description' => 'Default select list.',
    'preview' => array(
      'element1' => array(
        'title' => 'Select',
        'description' => 'Description',
        'options' => $options,
      ),
      'element2' => array(
        'title' => 'Select list with error.',
        'description' => 'Description',
        'attributes' => array(
          'disabled',
        ),
        'options' => $options,
      ),
      'element3' => array(
        'title' => 'Disabled select list.',
        'description' => 'Description',
        'attributes' => array(
          'class' => array(
            'ecl-select--has-error',
          ),
        ),
        'options' => $options,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_select(&$variables, $hook) {
  _ec_europa_form_set_css_class($variables, array('ecl-select'), array('ecl-select--has-error'));
}
