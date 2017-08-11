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
    'description' => 'Text field.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_textfield($form, &$form_state) {
  $form['element1'] = array(
    '#title' => 'Normal input',
    '#type' => 'textfield',
    '#description' => 'Description',
  );

  $form['element2'] = array(
    '#title' => 'Disabled input',
    '#type' => 'textfield',
    '#description' => 'Description',
    '#disabled' => TRUE,
  );

  $form['element3'] = array(
    '#title' => 'Input with error',
    '#type' => 'textfield',
    '#description' => 'Description',
    '#attributes' => array(
      'class' => array(
        'ecl-text-input--has-error',
      ),
    ),
  );

  return $form;
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
