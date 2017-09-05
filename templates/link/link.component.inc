<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function ec_europa_atomium_theme_link() {
  return array(
    'link' => array(
      'template' => 'link',
      'variables' => array(
        'text' => NULL,
        'path' => NULL,
        'options' => array(),
        'prefix' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_link() {
  return array(
    'label' => 'Link',
    'description' => 'Link template.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_link($form, &$form_state) {
  $variants = array(
    'Default' => 'default',
    'External' => 'external',
    'Standalone' => 'standalone',
    'Inverted' => 'inverted',
    'All' => 'all',
    'More' => 'more',
  );

  foreach ($variants as $value => $variant) {
    $form['links'][] = array(
      '#theme' => array('link__' . $variant),
      '#title' => t('Link type: @type', array('@type' => $value)),
      '#text' => $value,
      '#path' => current_path(),
      '#theme_wrappers' => array('form_element'),
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_link(&$variables, $hook) {
  $classes = &$variables['attributes_array']['class'];

  if (_ec_europa_array_find('ecl-', $classes)) {
    $classes[] = 'ecl-link';
  }

  // Add the class for the external links.
  if (_ec_europa_url_is_external($variables['path']) && (!in_array('ecl-icon', $classes))) {
    $classes[] = 'ecl-link--external';
  }

  // Add the span tag for the icon.
  if (in_array('ecl-icon', $classes)) {
    $icon_classes = array_filter($classes, function ($class, $key) use (&$classes) {
      if (FALSE !== stripos($class, 'ecl-icon') || FALSE !== stripos($class, '__social-icon')) {
        unset($classes[$key]);
        return TRUE;
      }
      return FALSE;
    }, ARRAY_FILTER_USE_BOTH);

    $variables['prefix'] = array(
      '#type' => 'html_tag',
      '#tag' => 'span',
      '#attributes' => array(
        'class' => $icon_classes,
      ),
    );
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__external(&$variables, $hook) {
  $variables['attributes_array']['class'][] = array(
    'ecl-link--external',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__standalone(&$variables, $hook) {
  $variables['attributes_array']['class'][] = array(
    'ecl-link--standalone',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__inverted(&$variables, $hook) {
  $variables['attributes_array']['class'][] = array(
    'ecl-link--inverted',
    'ecl-u-bg-shade',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__all(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-link--all',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__more(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-link--more',
  );
}
