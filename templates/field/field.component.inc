<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 */
function ec_europa_preprocess_field(array &$variables, $hook) {
  $element = &$variables['element'];

  if (isset($element['#label'])) {
    $variables['label'] = $element['#label'];
  }

  // @TODO refactor Add the tpl classes here
  // Changing label for the field to display stripped out values.
  switch ($variables['element']['#field_name']) {
    case 'field_core_social_network_links':
      $element['before'] = t('Follow the latest progress and get involved.');
      $element['after'] = l(t('Other social networks'), variable_get('dt_core_other_social_networks_link', 'http://europa.eu/contact/social-networks/index_en.htm'));

      break;
  }

  if ($element['#field_type'] !== 'ds') {
    if ($element['#field_type'] === 'entityreference' && $element['#field_translatable'] === 0) {
      if (isset($element['#language'])
        && $element['#language'] !== LANGUAGE_NONE
        && $GLOBALS['language_content']->language !== $element['#language']
      ) {
        $variables['attributes']['lang'] = $element['#language'];
      }
    }

    // Inject a specific class when a field might use the WYSIWYG editor.
    if (\in_array($element['#field_type'], array('text_with_summary', 'text_long'), TRUE)) {
      foreach (\array_keys($variables['items']) as $delta) {
        $variables['atomium']['attributes'][$delta]->append('class', 'ecl-editor');
      }
    }
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__taxonomy_term_reference_link(array &$variables, $hook) {
  _ec_europa_preprocess_taxonomy_term_reference_link($variables, $hook);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__i18n_taxonomy_term_reference_link(array &$variables, $hook) {
  _ec_europa_preprocess_taxonomy_term_reference_link($variables, $hook);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__taxonomy_term_reference_plain(array &$variables, $hook) {
  _ec_europa_preprocess_taxonomy_term_reference_plain($variables, $hook);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__i18n_taxonomy_term_reference_plain(array &$variables, $hook) {
  _ec_europa_preprocess_taxonomy_term_reference_plain($variables, $hook);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__entityreference__ne_tags(array &$variables, $hook) {
  _ec_europa_preprocess_ne_tags($variables, $hook);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__link_field__ne_tags(array &$variables, $hook) {
  _ec_europa_preprocess_ne_tags($variables, $hook);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__taxonomy_term_reference__ne_tags(array &$variables, $hook) {
  _ec_europa_preprocess_ne_tags($variables, $hook);
}

/**
 * Helper function to theme ne_tags formatters.
 *
 * See nexteuropa_formatters_fields.
 */
function _ec_europa_preprocess_ne_tags(array &$variables, $hook) {
  $variables['tags'] = array(
    '#theme' => _atomium_extend_theme_hook('tags', $variables['theme_hook_original']),
    '#label' => $variables['label'],
    '#items' => $variables['items'],
  );
}

/**
 * Helper function to theme taxonomy term link formatters.
 */
function _ec_europa_preprocess_taxonomy_term_reference_link(array &$variables, $hook) {
  $items = array();
  foreach ($variables['items'] as $item) {
    $items[] = array(
      'href' => $item['#href'],
      'value' => $item['#title'],
    );
  }
  $variables['tags'] = array(
    '#theme' => _atomium_extend_theme_hook('tags', $variables['theme_hook_original']),
    '#label' => $variables['label'],
    '#items' => $items,
  );
}

/**
 * Helper function to theme taxonomy term plain formatters.
 */
function _ec_europa_preprocess_taxonomy_term_reference_plain(array &$variables, $hook) {
  $variables['tags'] = array(
    '#theme' => _atomium_extend_theme_hook('tags', array('facet', $variables['theme_hook_original'])),
    '#label' => $variables['label'],
    '#items' => \array_map(function ($item) {
      return array(
        'href' => '',
        'value' => $item['#markup'],
      );
    }, $variables['items']),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_field__list_boolean__list_default__group_access__node__full__community(array &$variables, $hook) {
  if ($object = $variables['element']['#object']) {
    $wrapper = entity_metadata_wrapper('node', $object);

    \array_walk($variables['items'], function (&$item) use ($wrapper) {
      $item = array(
        '#content' => $item['#markup'],
      );
      // @todo: Should we compute the value from $wrapper for each items ?
      $variant = ($wrapper->group_access->value() === 0) ? 'closed' : 'open';
      $item['#theme'] = _atomium_extend_theme_hook('labels', $variant);
    });
  }
}
