<?php

/**
 * @file
 * Contains texfield component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_textfield() {
  return array(
    'label' => 'Text field',
    'description' => 'Default text field.',
    'preview' => array(
      'element1' => array(
        'title' => 'Text field',
        'description' => 'Description',
        'attributes' => array(
          'size' => 30,
        ),
      ),
      'element2' => array(
        'title' => 'Text field with error.',
        'description' => 'Description',
        'attributes' => array(
          'size' => 30,
          'class' => array(
            'ecl-text-input--has-error',
          ),
        ),
      ),
      'element3' => array(
        'title' => 'Disabled text field.',
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
function ec_europa_preprocess_textfield(&$variables, $hook) {
  $classes = array('ecl-text-input');
  $error_classes = array('ecl-text-input--has-error');
  _ec_europa_form_set_css_class($variables, $classes, $error_classes);
}

/**
 * Implements hook_preprocess_hook().
 *
 * It is related to the "search_bar" component based on Europa search
 * simple form.
 *
 * @see ec_europa_preprocess_textfield();
 */
function ec_europa_preprocess_textfield__nexteuropa_europa_search_search_form__querytext(&$variables, $hook) {
  $classes = array('ecl-search-form__textfield');
  _ec_europa_form_set_css_class($variables, $classes);
  $variables['attributes_array']['size'] = 30;
}
