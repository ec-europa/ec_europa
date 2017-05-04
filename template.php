<?php

/**
 * @file
 * template.php
 */

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
}

/**
 * Implements hook_ds_pre_render_alter().
 *
 * Setting variables for non-node entities in the DS templates.
 */
function europa_ds_pre_render_alter(&$layout_render_array, $context, &$variables) {
  $entity = $variables['elements'];
  $entity_type = $entity['#entity_type'];

  switch ($entity_type) {
    case 'user':
      $uri = entity_uri($entity_type, $variables['elements']['#account']);
      $variables['node_url'] = url($uri['path']);

      if (!empty($entity['europa_user_fullname_first'])) {
        $title = $entity['europa_user_fullname_first'][0]['#markup'];
      }
      elseif (!empty($entity['europa_user_fullname_last'])) {
        $title = $entity['europa_user_fullname_last'][0]['#markup'];
      }
      else {
        $title = $variables['elements']['#account']->name;
      }

      // We get the value wrapped in a <p> tag.
      $variables['title'] = strip_tags($title);
      break;

    case 'taxonomy_term':
      $uri = entity_uri($entity_type, $variables['term']);
      $variables['node_url'] = url($uri['path']);
      $variables['title'] = $entity['#term']->name;
      break;

  }
}

