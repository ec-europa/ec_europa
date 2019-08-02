<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function ec_europa_atomium_theme_link(array $existing, $type, $theme, $path) {
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
function ec_europa_atomium_definition_form_link(array $form, array &$form_state) {
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
      '#options' => array(
        'attributes' => array(
          'class' => $item['class'],
        ),
      ),
      '#theme_wrappers' => array('form_element'),
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ec_europa_preprocess_link(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', 'ecl-link');

  // Add the class for the external links.
  // @todo: This is not working as it should.
  if (\_ec_europa_url_is_external($variables['path'])
    && (!$variables['atomium']['attributes']['element']->exists('class', 'ecl-icon'))
    && (!$variables['atomium']['attributes']['element']->exists('class', 'ecl-icon-social'))
  ) {
    $variables['atomium']['attributes']['element']->append('class', 'ecl-link--external');
  }

  if (isset($variables['options']['attributes'])) {
    $variables['atomium']['attributes']['element']->merge($variables['options']['attributes']);
  }

  // Add the span tag for the icon.
  // @TODO: Do this.
  /*
  if ($variables['atomium']['attributes']['element']
  ->exists('class', 'ecl-icon')) {
  $icon_classes = array_filter(
  $classes,
  function ($class, $key) use (&$classes) {
  if (FALSE !== stripos($class, 'ecl-icon') || FALSE !== stripos(
  $class,
  '__social-icon'
  )) {
  unset($classes[$key]);
  return TRUE;
  }
  return FALSE;
  },
  ARRAY_FILTER_USE_BOTH
  );

  $variables['prefix'] = array(
  '#type' => 'html_tag',
  '#tag' => 'span',
  '#attributes' => array(
  'class' => $icon_classes,
  ),
  );
  }
   */
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__default(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--default',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__primary(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--primary',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__secondary(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--secondary',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__call(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--call',
    'ecl-button--caret-right',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__tags(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', 'ecl-tag__item');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__timeline(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--call',
    'ecl-button--caret-down',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_up(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret-up',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_right(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret-right',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_down(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret-down',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__caret_left(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--default',
    'ecl-button--caret_left',
  ));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link__primary_block(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array(
    'ecl-button',
    'ecl-button--primary',
    'ecl-button--block',
    'ecl-button--caret-down',
  ));
}
