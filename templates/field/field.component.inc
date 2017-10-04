<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field(&$variables, $hook) {
  $element = &$variables['element'];

  if (isset($element['#label'])) {
    $variables['label'] = $element['#label'];
  }

  if ($element['#field_type'] != 'ds') {
    // The default language code.
    $content_langcode = $GLOBALS['language_content']->language;
    // When the language is different from content.
    if (isset($element['#language'])
      && $element['#language'] != LANGUAGE_NONE
      && $element['#language'] != $content_langcode
    ) {
      $variables['attributes_array']['lang'] = $element['#language'];
    }
  }

  // In case of "Long text" or "Long text and summary" field, inject the
  // namespace class in the item class.
  if (in_array($element['#field_type'], array('text_with_summary', 'text_long'))) {
    $attributes_item = &$variables['attributes_item'];
    foreach ($variables['items'] as $delta => $item) {
      $attributes_item[$delta]['class'][] = 'ecl-editor';
    }
  }
}


/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__ne_tags(&$variables, $hook) {
  _ec_europa_preprocess_ne_tags($variables, $hook);
}

/**
 * Helper function to theme ne_tags formatters.
 *
 * See nexteuropa_formatters_fields.
 */
function _ec_europa_preprocess_ne_tags(&$variables, $hook) {
  $variables['tags'] = array(
    '#theme' => array('tags__' . $variables['theme_hook_original']),
    '#label' => $variables['label'],
    '#items' => $variables['items'],
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__list_boolean__list_default__group_access__node__full__community(&$variables, $hook) {
  if ($object = $variables['element']['#object']) {
    $wrapper = entity_metadata_wrapper('node', $object);

    $theme = 'labels__open';
    if (0 == $wrapper->group_access->value()) {
      $theme = 'labels__closed';
    }

    foreach ($variables['items'] as $delta => &$item) {
      $item = array(
        '#theme' => $theme,
        '#content' => $item['#markup'],
      );
    }
  }
}
