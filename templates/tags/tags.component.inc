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
        'modifier' => '',
        'label' => '',
        'tags' => array(),
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
    '#tags' => array(
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
    '#theme' => 'tags',
    '#label' => 'containing',
    '#modifier' => 'facet',
    '#tags' => array(
      array(
        'value' => 'Words that the facet is containing',
      ),
    ),
  );

  $form['element3'] = array(
    '#theme' => 'tags',
    '#modifier' => 'facet-close',
    '#label' => 'type',
    '#tags' => array(
      array(
        'value' => 'atom',
      ),
    ),
  );
  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_tags(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-tag';
  if (!empty($variables['modifier'])) {
    $variables['attributes_array']['class'][] = 'ecl-tag--' . $variables['modifier'];
    switch ($variables['modifier']) {
      case 'facet-close':
        foreach ($variables['tags'] as $key => $tag) {
          $variables['tags'][$key] = array(
            '#theme' => 'button__' . $hook,
            '#value' => $tag['value'],
          );
        }
        break;

      case 'facet':
        foreach ($variables['tags'] as $key => $tag) {
          $variables['tags'][$key] = array(
            '#type' => 'html_tag',
            '#tag' => 'span',
            '#attributes' => array(
              'class' => 'ecl-tag__item',
            ),
            '#value' => $tag['value'],
          );
        }
        break;

    }
  }
  else {
    foreach ($variables['tags'] as $key => $tag) {
      $variables['tags'][$key] = array(
        '#theme' => 'link__' . $hook,
        '#text' => $tag['value'],
        '#path' => $tag['href'],
      );
    };
  }
  $variables['title_attributes_array']['class'][] = 'ecl-tag__label';
}
