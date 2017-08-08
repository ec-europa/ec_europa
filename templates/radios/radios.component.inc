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
    'label' => 'Radio group',
    'description' => 'Radio group component.',
    'preview' => array(
      'element1' => array(
        'title' => 'Radio group title',
        'title_display' => 'before',
        'description' => 'Radio group description',
        'options' => $options,
        'default_value' => 'item1',
        array(
          array(
            '#type' => 'radio',
            '#title' => 'N/A',
            '#value' => '0',
          ),
        ),
        array(
          array(
            '#type' => 'radio',
            '#title' => 'Red',
          ),
        ),
        array(
          array(
            '#type' => 'radio',
            '#title' => 'Green',
          ),
        ),
        array(
          array(
            '#type' => 'radio',
            '#title' => 'Blue',
          ),
        ),
        array(
          array(
            '#type' => 'radio',
            '#title' => 'Yellow',
          ),
        ),
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
    $descr_attributes_array['class'] = array('ecl-sr-only');
    if (isset($descr_attributes_array['id'])) {
      $descr_attributes_array['id'] = array($element['#id'] . "-description");
    }
    $variables['descr_attributes_array'] = $descr_attributes_array;
    $variables['description'] = $element['#description'];
  }
}
