<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radio(&$variables, $hook) {
  $classes = array(
    'default' => array('ecl-radio__input', 'ecl-sr-only'),
  );
  _ec_europa_form_set_css_class($variables, $classes);

  // Sets the attributes of the label tag that surrounds the radio button.
  $label_tag_attributes = array(
    'class' => array('ecl-form-label', 'ecl-radio'),
  );

  // Unlike text field and textarea, the "error" class is put on the label;
  // not on the element itself.
  $element = $variables['element'];
  if (isset($element['#parents']) && form_get_error($element) !== NULL && !empty($element['#validated'])) {
    $label_tag_attributes['class'][] = 'ecl-radio--has-error';
  }
  // Add the class to put with a radio button when it is disabled.
  if (!empty($element['#disabled'])) {
    $label_tag_attributes['class'][] = 'ecl-radio--is-disabled';
  }
  $variables['label_tag_attributes'] = atomium_drupal_attributes($label_tag_attributes);

  // The radio button label is integrated in the button display.
  $variables['label'] = array(
    '#theme' => array('form_element_label'),
    'element' => $element,
  );
}
