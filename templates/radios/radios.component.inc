<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_radios() {
  $options = array(
    'item1' => 'Item 1',
    'item2' => 'Item 2',
    'item3' => 'Item 3',
    'item4' => 'Item 4',
  );
  return array(
    'label' => 'Radio groups',
    'description' => 'Radio groups component.',
    'preview' => array(
      'element1' => array(
        'title' => 'Radio groups',
        'title_display' => 'before',
        'description' => 'Description',
        'options' => $options,
        'default_value' => 'item1',
        'children' => '
          <label class="ecl-form-label ecl-radio"><input class="ecl-radio__input ecl-sr-only form-radio" id="edit-field-radios-en-none" name="field_radios[en]" type="radio" value="_none"/><span class="ecl-radio__label">N/A</span> </label> 
          <label class="ecl-form-label ecl-radio"><input class="ecl-radio__input ecl-sr-only form-radio" id="edit-field-radios-en-red" name="field_radios[en]" type="radio" value="red"/><span class="ecl-radio__label">Red</span> </label> 
          <label class="ecl-form-label ecl-radio"><input class="ecl-radio__input ecl-sr-only form-radio" id="edit-field-radios-en-green" name="field_radios[en]" type="radio" value="green"/><span class="ecl-radio__label">Green</span> </label> 
          <label class="ecl-form-label ecl-radio"><input class="ecl-radio__input ecl-sr-only form-radio" id="edit-field-radios-en-blue" name="field_radios[en]" type="radio" value="blue"/><span class="ecl-radio__label">Blue</span> </label> 
          <label class="ecl-form-label ecl-radio"><input class="ecl-radio__input ecl-sr-only form-radio" id="edit-field-radios-en-yellow" name="field_radios[en]" type="radio" value="yellow"/><span class="ecl-radio__label">Yellow</span> </label>',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radios(&$variables, $hook) {
  $element = $variables['element'];
  $variables['attributes_array']['class'][] = 'ecl-radio-group';
  $variables['attributes_array']['role'][] = 'radiogroup';
  if (!empty($element['#title'])) {
    $title = $element['#title'];
    $variables['attributes_array']['aria-labelledby'][] = $title;
    $variables['small_description'] = t('List of options for @title', array('@title' => $title));
  }

  if (!empty($element['#description'])) {
    $descr_attributes['class'] = array('ecl-sr-only');
    if (isset($descr_attributes['id'])) {
      $descr_attributes['id'] = array($element['#id'] . "-description");
    }
    $variables['descr_attributes'] = atomium_drupal_attributes($descr_attributes);
    $variables['description'] = $element['#description'];
  }
}
