<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radio(&$variables) {
  $variables['attributes_array']['class'][] = 'ecl-radio__input';
  $variables['attributes_array']['class'][] = 'ecl-sr-only';

  // Sets the attributes of the label tag that surrounds the radio button.
  $label_tag_attributes = array(
    'class' => array('ecl-form-label', 'ecl-radio'),
  );
  $variables['label_tag_attributes'] = atomium_drupal_attributes($label_tag_attributes);
}
