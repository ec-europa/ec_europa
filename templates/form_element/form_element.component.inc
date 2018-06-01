<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element__radio(array &$variables, $hook) {
  $element = $variables['element'];

  if (isset($element['#label_tag_attributes'])) {
    $variables['atomium']['attributes']['label']->merge(
      $element['#label_tag_attributes']
    );
  }

  $variables['atomium']['attributes']['label']->append(
    'class',
    'ecl-form-label'
  );
  $variables['atomium']['attributes']['label']->append('class', 'ecl-radio');
  if (isset($element['#id'])) {
    $variables['atomium']['attributes']['label']->append(
      'for',
      $element['#id']
    );
  }

  // Unlike text field and textarea, the "error" class is added on the label;
  // not on the element itself.
  if (_ec_europa_has_form_element_errors($element)) {
    $variables['atomium']['attributes']['label']->append(
      'class',
      'ecl-radio--has-error'
    );
  }
  // Add the class to put with a radio button when it is disabled.
  if (!empty($element['#disabled'])) {
    $variables['atomium']['attributes']['label']->append(
      'class',
      'ecl-radio--is-disabled'
    );
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element__checkbox(array &$variables, $hook) {
  $element = $variables['element'];

  if (isset($element['#label_tag_attributes'])) {
    $variables['atomium']['attributes']['label']->merge(
      $element['#label_tag_attributes']
    );
  }

  $variables['atomium']['attributes']['label']->append(
    'class',
    'ecl-form-label'
  );
  $variables['atomium']['attributes']['label']->append('class', 'ecl-checkbox');
  if (isset($element['#id'])) {
    $variables['atomium']['attributes']['label']->append(
      'for',
      $element['#id']
    );
  }

  // Unlike text field and textarea, the "error" class is added on the label;
  // not on the element itself.
  if (_ec_europa_has_form_element_errors($element)) {
    $variables['atomium']['attributes']['label']->append(
      'class',
      'ecl-checkbox--has-error'
    );
  }

  // Add the class to put with a checkbox button when it is disabled.
  if (!empty($element['#disabled'])) {
    $variables['atomium']['attributes']['label']->append(
      'class',
      'ecl-checkbox--is-disabled'
    );
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element__textarea(array &$variables, $hook) {
  $variables['label']['#attributes'] = array(
    'id' => array($variables['element']['#id'] . '_label'),
  );
}
