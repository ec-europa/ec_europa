<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_radio() {
  $options = array(
    'item1' => 'Item 1',
  );
  return array(
    'label' => 'Radio button',
    'description' => 'Radio component.',
    'preview' => array(
      'element1' => array(
        'title' => 'Radio button',
        'description' => 'Description',
        'options' => $options,
      ),
      'element2' => array(
        'title' => 'Radio button checked',
        'description' => 'Description',
        'default_value' => 'item1',
        'options' => $options,
      ),
      'element3' => array(
        'title' => 'Radio button with error',
        'description' => 'Description',
        'attributes' => array(
          'class' => array(
            'error',
          ),
        ),
        'options' => $options,
      ),
      'element4' => array(
        'title' => 'Radio button disabled',
        'description' => 'Description',
        'disabled' => TRUE,
        'attributes' => array(
          'disabled',
        ),
        'options' => $options,
      ),
    ),
  );
}

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
  // $error_css_exists allows the compatibility with the component overview
  // page but in a normal runtime process, we should not rely on it as nothing
  // prevents a module or another process to change it, we secure the test with
  // private function.
  $error_css_exists = in_array('error', $variables['attributes_array']['class']);
  if ($error_css_exists || (_ec_europa_has_form_element_errors($element))) {
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
