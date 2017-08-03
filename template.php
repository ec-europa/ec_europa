<?php

/**
 * @file
 * template.php
 */

atomium_include('ec_europa', 'includes/alter');

/**
 * Implements hook_date_popup_process_alter().
 */
function ec_europa_date_popup_process_alter(&$element, &$form_state, $context) {
  // Removing the description from the datepicker.
  unset($element['date']['#description']);
  unset($element['time']['#description']);
}

/**
 * Override theme_file_link().
 *
 * TODO: Convert this into a preprocess function.
 */
function ec_europa_file_link($variables) {
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
 *
 * TODO: This function doesn't seems to be used in this theme.
 */
function _ec_europa_term_heading($element) {
  $element['#prefix'] = '<div class="container-fluid"><div class="' . $element['main'] . '">';
  $element['#suffix'] = '</div></div>';
  return $element;
}

/**
 * Sets a form element's class attribute.
 *
 * Adds the 'ecl-text-input--has-error' class as needed.
 *
 * @param array $element
 *   The form element.
 * @param array $classes
 *   The basic classes that are specific to the form element.
 */
function _ec_europa_form_set_css_class(array &$element, array $classes = array()) {
  if (!empty($classes)) {
    if (!isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = array();
    }
    $element['#attributes']['class'] = array_merge($element['#attributes']['class'], $classes);
  }

  // Determines if the error class must added.
  // The logic comes from the Drupal function: "_form_set_class".
  if (isset($element['#parents']) && form_get_error($element) !== NULL && !empty($element['#validated'])) {
    $element['#attributes']['class'][] = 'ecl-text-input--has-error';
  }
}

/**
 * Returns HTML for a dropdown.
 */
function ec_europa_dropdown(array $variables) {
  $items = $variables['items'];
  $links = array();

  $select = array(
    '#title' => t('Create content'),
    '#type' => 'select',
    '#description' => t('Create content'),
    '#options' => array('#' => t('Create content')),
  );

  foreach ($items as $key => $value) {
    $links[$value] = $key;
  }
  $select['#options'] = array_merge($select['#options'], array_map('t', $links));

  return form_select_options($select);
}

/**
 * Case array_search() with partial matches.
 *
 * @param string $needle
 *   The string to search for.
 * @param array $haystack
 *   The array to search in.
 *
 * @return mixed
 *   The key for needle if it is found in the
 *   array, FALSE otherwise.
 *
 * @author Bran van der Meer <branmovic@gmail.com>
 */
function _ec_europa_array_find($needle, array $haystack) {
  foreach ($haystack as $key => $value) {
    if (is_string($value) && FALSE !== stripos($value, $needle)) {
      return $key;
    }
  }
  return FALSE;
}

/**
 * Returns TRUE if a path is external to Drupal and 'ec.europa.eu' domain.
 *
 * @param string $path
 *   The internal path or external URL being linked to, such as "node/34" or
 *   "http://example.com/foo".
 *
 * @return bool
 *   Boolean TRUE or FALSE, where TRUE indicates an external path.
 */
function _ec_europa_url_is_external($path) {
  return url_is_external($path) && !stripos(parse_url($path, PHP_URL_HOST), 'europa.eu');
}
