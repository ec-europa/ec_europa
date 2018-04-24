<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_site_switcher(array $existing, $type, $theme, $path) {
  return array(
    'site_switcher' => array(
      'template' => 'site-switcher',
      'variables' => array(
        'links' => NULL,
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_site_switcher() {
  return array(
    'label' => 'Site Switcher',
    'description' => 'Site Switcher.',
    'preview' => array(),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_site_switcher(array &$variables, $hook) {
  global $language;

  $variables['atomium']['attributes']['wrapper']->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']->append('class', array(
    'ecl-site-switcher',
  ))->append(
    'aria-label', 'breadcrumbs'
  );

  $classes = \array_pad(array(), 2, array('ecl-site-switcher__option'));
  $index = (int) theme_get_setting('ec_europa_improved_website', 'ec_europa');
  $classes[$index][] = 'ecl-site-switcher__option--is-selected';

  $links = array(
    array(
      '#text' => t('Commission and its priorities'),
      '#path' => 'https://ec.europa.eu/commission/index_' . $language->language,
    ),
    array(
      '#text' => t('Policies, information and services'),
      '#path' => 'https://ec.europa.eu/info/index_' . $language->language,
    ),
  );

  $variables['links'] = array(
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#wrapper' => FALSE,
    '#attributes' => array(
      'class' => array('ecl-site-switcher__list', 'ecl-container'),
    ),
    '#items' => array(),
  );

  foreach ($links as $key => $link) {
    $link = array(
      '#theme' => 'link',
      '#options' => array(
        'attributes' => array(
          'class' => array('ecl-link ecl-site-switcher__link'),
        ),
        'html' => FALSE,
      ),
    ) + $link;

    _atomium_extend_theme_property(
      $link,
      array($variables['theme_hook_original']));

    $variables['links']['#items'][] = array(
      'class' => $classes[$key],
      'data' => $link,
    );
  }

  _atomium_extend_theme_property(
    $variables['links'],
    array($variables['theme_hook_original']));
}
