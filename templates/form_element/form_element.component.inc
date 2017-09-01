<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 *
 * Adds the attributes specific to the radio form element.
 */
function ec_europa_preprocess_form_element__radio(&$variables, $hook) {
  $element = $variables['element'];

  // Define the variable specific to the radio label tag.
  // Sets the attributes of the label tag that surrounds the radio button.
  $label_tag_attributes_array = [];

  if (isset($element['#label_tag_attributes'])) {
    $label_tag_attributes_array = $element['#label_tag_attributes'];
  }

  $label_tag_attributes_array += ['class' => []];
  $label_tag_attributes_array['class'][] = 'ecl-form-label';
  $label_tag_attributes_array['class'][] = 'ecl-radio';

  // Unlike text field and textarea, the "error" class is added on the label;
  // not on the element itself.
  if (_ec_europa_has_form_element_errors($element)) {
    $label_tag_attributes_array['class'][] = 'ecl-radio--has-error';
  }
  // Add the class to put with a radio button when it is disabled.
  if (!empty($element['#disabled'])) {
    $label_tag_attributes_array['class'][] = 'ecl-radio--is-disabled';
  }
  $variables['label_tag_attributes_array'] = $label_tag_attributes_array;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element__checkbox(&$variables, $hook) {
  $element = $variables['element'];

  // Define the variable specific to the checkbox label tag.
  // Sets the attributes of the label tag that surrounds the checkbox button.
  $label_tag_attributes_array = array();

  if (isset($element['#label_tag_attributes'])) {
    $label_tag_attributes_array = $element['#label_tag_attributes'];
  }

  $label_tag_attributes_array += array('class' => array());
  $label_tag_attributes_array['class'][] = 'ecl-form-label';
  $label_tag_attributes_array['class'][] = 'ecl-checkbox';

  // Unlike text field and textarea, the "error" class is added on the label;
  // not on the element itself.
  if (_ec_europa_has_form_element_errors($element)) {
    $label_tag_attributes_array['class'][] = 'ecl-checkbox--has-error';
  }

  // Add the class to put with a checkbox button when it is disabled.
  if (!empty($element['#disabled'])) {
    $label_tag_attributes_array['class'][] = 'ecl-checkbox--is-disabled';
  }

  $variables['label_tag_attributes_array'] = $label_tag_attributes_array;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element__textarea(&$variables, $hook) {
  $variables['label']['#attributes'] = array(
    'id' => array($variables['element']['#id'] . '_label'),
  );
}
