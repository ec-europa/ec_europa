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
    'description' => 'Link.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_link($form, &$form_state) {
  $type = array(
    array(
      'text' => 'in-line link',
      'class' => array('ecl-link'),
    ),
    array(
      'text' => 'external link',
      'class' => array(
        'ecl-link',
        'ecl-link--external',
      ),
    ),
    array(
      'text' => 'standalone link',
      'class' => array(
        'ecl-link',
        'ecl-link--standalone',
      ),
    ),
    array(
      'text' => 'inverted link',
      'class' => array(
        'ecl-link',
        'ecl-link--inverted',
        'ecl-u-bg-shade',
      ),
    ),
    array(
      'text' => 'all link',
      'class' => array(
        'ecl-link',
        'ecl-link--all',
      ),
    ),
    array(
      'text' => 'more link',
      'class' => array(
        'ecl-link',
        'ecl-link--more',
      ),
    ),
    array(
      'text' => 'social link',
      'class' => array(
        'ecl-link',
        'ecl-icon-social',
        'ecl-icon-social--facebook',
      ),
    ),
  );

  foreach ($type as $item) {
    $form['element'][] = array(
      '#theme' => 'link',
      '#title' => 'Link for ' . $item['text'],
      '#text' => $item['text'],
      '#attributes_array' => array(
        'class' => $item['class'],
      ),
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
function ec_europa_preprocess_link__default(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--default',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__primary(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--primary',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__secondary(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--secondary',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__call(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--call',
    'ecl-button--caret-right',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__timeline(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--call',
    'ecl-button--caret-down',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_up(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret-up',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_right(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret-right',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_down(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret-down',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_left(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret_left',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__primary_block(&$variables, $hook) {
  $variables['attributes_array']['class'] = array(
    'ecl-button',
    'ecl-button--primary',
    'ecl-button--block',
    'ecl-button--caret-down',
  );
}
