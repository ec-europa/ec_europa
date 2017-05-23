<?php

/**
 * @file
 * template.php
 */

atomium_include('atomium', 'includes/alter');
atomium_include('europa', 'includes/alter');

/**
 * Implements hook_theme().
 */
function europa_theme($existing, $type, $theme, $path) {
  return [
    'europa_status_message' => [
      'template' => 'status_message',
      'path' => $path . '/templates',
      'variables' => [
        'message_classes' => '',
        'message_title' => '',
        'message_type' => '',
        'message_body' => '',
      ],
    ],
  ];
}

/**
 * Implements hook_preprocess_HOOK().
 */
function europa_preprocess_europa_status_message(&$variables) {
  if (!empty($variables['message_classes']) && is_array($variables['message_classes'])) {
    $variables['message_classes'] = ' ' . implode(' ', $variables['message_classes']);
  }
}

/**
 * Overrides theme_form_required_marker().
 */
function europa_form_required_marker($variables) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = [
    'class' => 'form-required text-danger',
    'title' => $t('This field is required.'),
  ];
  return '<span' . drupal_attributes($attributes) . '>*</span>';
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function europa_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  // Button value change on all the views exposed forms is due to a
  // design/ux requirement which uses the 'Refine results' label for all the
  // filter forms.
  $form['submit']['#value'] = t('Refine results');
  $form['submit']['#attributes']['class'][] = 'btn-primary';
  $form['submit']['#attributes']['class'][] = 'filters__btn-submit';
  $form['reset']['#attributes']['class'][] = 'filters__btn-reset';
}

/**
 * Implements hook_date_popup_process_alter().
 */
function europa_date_popup_process_alter(&$element, &$form_state, $context) {
  // Removing the description from the datepicker.
  unset($element['date']['#description']);
  unset($element['time']['#description']);
}

/**
 * Override theme_file_link().
 */
function europa_file_link($variables) {
  if (function_exists('_nexteuropa_formatters_file_markup')) {
    $file = $variables['file'];

    // Submit the language along witht the file.
    $langcode = $GLOBALS['language_content']->language;
    if (!empty($langcode)) {
      $file->language = $langcode;
    }

    return _nexteuropa_formatters_file_markup($file);
  }
  else {
    return theme_file_link($variables);
  }
}

/**
 * Pre-render function for taxonomy pages.
 */
function _europa_term_heading($element) {
  $element['#prefix'] = '<div class="container-fluid"><div class="' . $element['main'] . '">';
  $element['#suffix'] = '</div></div>';
  return $element;
}
