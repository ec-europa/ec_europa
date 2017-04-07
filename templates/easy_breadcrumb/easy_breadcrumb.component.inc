<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function europa_atomium_theme_easy_breadcrumb(&$variables, $hook) {
  return array(
    'easy_breadcrumb' => array(
      'variables' => array(
        'breadcrumb' => NULL,
        'segments_quantity' => NULL,
        'separator' => NULL,
      ),
      'template' => 'easy-breadcrumb',
    ),
  );
}

/**
 * Implements hook_atomium_definition_HOOK().
 */
function europa_atomium_definition_easy_breadcrumb() {
  return array(
    'label' => 'Easy breadcrumb',
    'description' => 'Easy breadcrumb.',
    'preview' => array(
      'segments_quantity' => 3,
      'breadcrumb' => array(
        array(
          'content' => 'Home',
          'url' => '/',
        ),
        array(
          'content' => 'News',
          'url' => '/',
        ),
        array(
          'content' => t('My news title'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function europa_preprocess_easy_breadcrumb(&$variables, $hook) {
  _europa_breadcrumb_menu($variables);
  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $html = '';

  if ($segments_quantity > 0) {
    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/breadcrumb.js');

    for ($i = 0, $s = $segments_quantity; $i < $segments_quantity; ++$i) {
      $item = $breadcrumb[$i];

      // Removing classes from $item['class'] array and adding BEM classes.
      $classes = array();
      if (isset($item['class'])) {
        $classes = $item['class'];
      }
      $classes[] = 'breadcrumb__segment';

      $attributes = [
        'class' => ['breadcrumb__link', 'plop'],
      ];

      if ($i == 0) {
        $classes[] = 'breadcrumb__segment--first';
        $attributes['class'][] = 'is-internal';
        $attributes += ['rel' => 'home'];
      }
      elseif ($i == ($s - 1)) {
        $classes[] = 'breadcrumb__segment--last';
      }

      $content = '<span class="breadcrumb__text">' . check_plain(decode_entities($item['content'])) . '</span>';
      $class = implode(' ', $classes);
      if (isset($item['url'])) {
        $full_item = l($content, $item['url'], [
          'attributes' => $attributes,
          'html' => TRUE,
        ]);
      }
      else {
        $full_item = '<span class="' . $class . '">' . $content . '</span>';
      }

      // TODO: Check if the active class actually appears.
      $element_visibility = in_array('active', $classes) ? ' element-invisible' : '';
      $html .= '<li class="' . $class . $element_visibility . '">' . $full_item . '</li>';
    }
  }

  $variables[$hook] = $html;
}
