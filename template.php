<?php

/**
 * @file
 * template.php
 */

/**
 * Include common functions used through out theme.
 */
include_once __DIR__ . '/includes/common.inc';

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
  if (\function_exists('_nexteuropa_formatters_file_markup')) {
    $file = $variables['file'];

    // Submit the language along witht the file.
    $langcode = $GLOBALS['language_content']->language;
    if (!empty($langcode)) {
      $file->language = $langcode;
    }

    return _nexteuropa_formatters_file_markup($file);
  }

  return theme_file_link($variables);
}

/**
 * Pre-render function for taxonomy pages.
 *
 * TODO: This function doesn't seems to be used in this theme.
 */
function _ec_europa_term_heading($element) {
  $element['#prefix'] = '<div class="ecl-container"><div class="' . $element['main'] . '">';
  $element['#suffix'] = '</div></div>';

  return $element;
}

/**
 * Sets a form element's class attribute.
 *
 * Adds the css classes as needed.
 *
 * @param array $variables
 *   The $variables related to the form element theme.
 * @param array $classes
 *   The array of class names to add to the element by default.
 * @param array $error_classes
 *   The array of class names to add to the element in case of
 *   validation errors.
 *
 * @return array
 *   The modified $variables array.
 */
function _ec_europa_form_set_css_class(array &$variables, array $classes = array(), array $error_classes = array()) {
  if (!empty($classes)) {
    $variables['atomium']['attributes']['element']->append('class', $classes);
  }

  // Determines if the error class must added.
  // The logic comes from the Drupal function, see _form_set_class().
  if (isset($variables['element'])) {
    $element = $variables['element'];
    if (!empty($error_classes) && _ec_europa_has_form_element_errors($element)) {
      $variables['atomium']['attributes']['element']->append('class', $error_classes);
    }
  }

  return $variables;
}

/**
 * Determines if validation errors exists on a form element.
 *
 * This method works only with elements processed by the theme mechanism.
 *
 * @param array $form_element
 *   The form element to test as defined in the $variable parameter of a
 *   preprocess function.
 *
 * @return bool
 *   True if validation errors exist; otherwise FALSE.
 */
function _ec_europa_has_form_element_errors(array $form_element) {
  return isset($form_element['#parents']) && form_get_error($form_element) !== NULL && !empty($form_element['#validated']);
}

/**
 * Custom implementation of tableselect.
 */
function ec_europa_tableselect($variables) {
  // Add a custom JS file that overrides a specific JS function.
  drupal_add_js(path_to_theme() . '/templates/table/tableselect.js', array('group' => JS_THEME));

  // Use the default implementation to render the table.
  // We cannot use theme('tableselect',...) or else we will end up in a loop.
  // Better solutions are welcome.
  return theme_tableselect($variables);
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
    if (\is_string($value) && \stripos($value, $needle) !== FALSE) {
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
  return url_is_external($path) && !\stripos(\parse_url($path, PHP_URL_HOST), 'europa.eu') && \stripos(\parse_url($path, PHP_URL_HOST), $_SERVER['HTTP_HOST']) === FALSE;
}
