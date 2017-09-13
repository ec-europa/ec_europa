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
  if ($element['#field_type'] <> 'ds') {
    // Initialize parameter.
    $allow_attribute = TRUE;
    // If it is not a tranlateable entityreference field we should continue.
    if ($element['#field_type'] == "entityreference" && $element['#field_translatable'] == 0) {
      $allow_attribute = FALSE;
    }
    if ($allow_attribute) {
      // The default language code.
      $content_langcode = $GLOBALS['language_content']->language;
      // When the language is different from content.
      if (isset($element['#language'])
        && $element['#language'] <> LANGUAGE_NONE
        && $element['#language'] <> $content_langcode
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
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__ne_tags(&$variables, $hook) {
  $variables['tags'] = array(
    '#theme' => array('tags__' . $variables['theme_hook_original']),
    '#label' => $variables['label'],
    '#items' => $variables['items'],
  );
}
