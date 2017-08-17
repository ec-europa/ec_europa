<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_expandable() {
  return array(
    'expandable' => array(
      'variables' => array(
        'title' => NULL,
        'body' => NULL,
        'id' => 'expandable',
        'button' => FALSE,
      ),
      'template' => 'expandable',
    ),
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_expandable($form, &$form_state) {
  $form['element1'] = array(
    '#theme' => 'expandable',
    '#title' => 'Expandable with a button',
    '#body' => '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit</p>',
    '#button' => TRUE,
  );

  $form['element2'] = array(
    '#theme' => 'expandable',
    '#title' => 'Expandable with a link',
    '#body' => '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit</p>',
  );

  return $form;
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_expandable() {
  return array(
    'label' => 'Expandable',
    'description' => 'Expandable.',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_expandable(&$variables, $hook) {
  $id = drupal_html_id($variables['id']);

  $variables['content_attributes_array'] = array(
    'class' => array(),
    'id' => $id,
    'aria-hidden' => 'true',
    'aria-labelledby' => $id . '-button',
  );

  $variables['link'] = array(
    '#theme' => array('link__' . $variables['theme_hook_original']),
    '#text' => $variables['title'],
    '#path' => '#',
    '#attributes_array' => array(
      'id' => $id . '-button',
      'class' => array(
        'ecl-expandable__button',
        'ecl-link',
      ),
      'aria-controls' => $id,
      'aria-expanded' => 'false',
      'onClick' => 'return false;',
    ),
  );

  if (isset($variables['button']) && TRUE == $variables['button']) {
    $variables['link'] = array(
      '#theme' => array('button__' . $variables['theme_hook_original']),
      '#button_type' => 'button',
      '#value' => $variables['title'],
      '#attributes' => array(
        'id' => $id . '-button',
        'class' => array(
          'ecl-expandable__button',
          'ecl-button',
        ),
        'aria-controls' => $id,
        'aria-expanded' => 'false',
      ),
    );
  }
}
