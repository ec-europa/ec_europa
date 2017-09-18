<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_tags() {
  return array(
    'tags' => array(
      'variables' => array(
        'label' => '',
        'items' => array(),
      ),
      'template' => 'tags',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_tags() {
  return array(
    'label' => 'Tags',
    'description' => 'Tags template.',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_tags($form, &$form_state) {
  $form['element1'] = array(
    '#theme' => 'tags',
    '#label' => 'Default tags',
    '#items' => array(
      array(
        'value' => 'apple',
        'href' => '#',
      ),
      array(
        'value' => 'orange',
        'href' => '#',
      ),
      array(
        'value' => 'lime',
        'href' => '#',
      ),
      array(
        'value' => 'strawberry',
        'href' => '#',
      ),
    ),
  );

  $form['element2'] = array(
    '#theme' => 'tags__facet',
    '#modifier' => 'facet',
    '#items' => array(
      array(
        'value' => 'Words that the facet is containing',
        'href' => '',
      ),
    ),
  );

  $form['element3'] = array(
    '#theme' => 'tags__facet_close',
    '#label' => 'type',
    '#items' => array(
      array(
        'value' => 'atom',
        'href' => '',
      ),
    ),
  );
  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_tags(&$variables, $hook) {
  // Store initial items.
  $variables['tags'] = $variables['items'];
  $variables['attributes_array']['class'][] = 'ecl-tag';
  $variables['title_attributes_array']['class'][] = 'ecl-tag__label';
  foreach ($variables['tags'] as $key => $tag) {
    $variables['items'][$key] = array(
      '#theme' => array('link__' . $variables['theme_hook_original']),
      '#text' => $tag['value'],
      '#path' => $tag['href'],
    );
  };
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_tags__facet(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-tag--facet';
  foreach ($variables['tags'] as $key => $tag) {
    $variables['items'][$key] = array(
      '#type' => 'html_tag',
      '#tag' => 'span',
      '#attributes' => array(
        'class' => 'ecl-tag__item',
      ),
      '#value' => $tag['value'],
    );
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_tags__facet_close(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-tag--facet-close';
  foreach ($variables['tags'] as $key => $tag) {
    $variables['items'][$key] = array(
      '#theme' => array('button__' . $variables['theme_hook_original']),
      '#value' => $tag['value'],
    );
  }
}
