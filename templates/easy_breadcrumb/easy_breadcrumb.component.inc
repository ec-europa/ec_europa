<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_easy_breadcrumb(array $existing, $type, $theme, $path) {
  return array(
    'easy_breadcrumb' => array(
      'variables' => array(
        'segments_quantity' => NULL,
        'breadcrumb' => NULL,
      ),
      'template' => 'easy-breadcrumb',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_easy_breadcrumb() {
  return array(
    'label' => 'Easy breadcrumb',
    'description' => 'Easy breadcrumb.',
    'preview' => array(
      'prefix' => '<div style="background-color: #004494; padding: 5px 15px 15px; float: left; width: 100%;">',
      'suffix' => '</div>',
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
          'content' => '',
        ),
      ),
    ),
    'dependencies' => array(
      'easy_breadcrumb',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_easy_breadcrumb(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']
    ->append(
      'class',
      array(
        'ecl-breadcrumb',
        'ecl-container',
      )
    )
    ->append(
      'aria',
      'breadcrumb'
    );

  $variables['here'] = t('You are here');

  _ec_europa_breadcrumb_menu($variables);
  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $html = array();

  $s = count($breadcrumb);

  if ($segments_quantity > 0) {
    foreach ($breadcrumb as $i => $item) {
      // Removing classes from $item['class'] array and adding BEM classes.
      $classes = array();
      if (isset($item['class'])) {
        $classes = $item['class'];
      }
      $classes[] = 'ecl-breadcrumb__segment';

      $attributes = array(
        'class' => array(
          'ecl-breadcrumb__link',
          'ecl-link--inverted',
          'ecl-link--standalone',
        ),
      );

      if ($i === 0) {
        $classes[] = 'ecl-breadcrumb__segment--first';
        $attributes['class'][] = 'is-internal';
        $attributes += array('rel' => 'home');
      }

      if ($i === ($s - 1)) {
        $classes[] = 'ecl-breadcrumb__segment--last';
      }

      $full_item = array(
        'link' => array(
          '#markup' => $item['content'],
        ),
      );

      if (isset($item['url'])) {
        $full_item = array(
          'link' => array(
            '#theme' => _atomium_extend_theme_hook(
              'link',
              $variables['theme_hook_original']
            ),
            '#text' => $item['content'],
            '#path' => $item['url'],
            '#options' => array(
              'attributes' => $attributes,
              'html' => TRUE,
            ),
          ),
        );
      }

      // TODO: Check if the active class actually appears.
      if (\in_array('active', $classes, TRUE)) {
        $classes[] = 'element-invisible';
      }

      $full_item += array(
        '#theme_wrappers' => array(
          'html_tag',
        ),
        '#tag' => 'li',
        '#attributes' => array(
          'class' => $classes,
        ),
      );

      $html[] = $full_item;
    }
  }

  $variables['easy_breadcrumb'] = $html;
}

/**
 * Generate the first breadcrumb items basing on a custom menu.
 */
function _ec_europa_breadcrumb_menu(&$variables) {
  $variables['breadcrumb'] = _easy_breadcrumb_build_items();
  $menu_links = menu_tree('menu-breadcrumb-menu');
  $new_items = array();
  global $language;
  $front = drupal_is_front_page();

  if (!empty($menu_links)) {
    $i = 0;
    foreach ($menu_links as $key => $menu_item) {
      if (\is_numeric($key)) {
        // We don't want to show the home link in the home page.
        if (!($front && $menu_item['#href'] === '<front>')) {
          $options = array('language' => $language);
          $title = token_replace($menu_item['#title'], $menu_item,
            $options);
          $new_items[] = _easy_breadcrumb_build_item($title, array(),
            $menu_item['#href']);
          $i++;
        }
      }
    }

    if (!empty($new_items)) {
      // The menu is used as the starting point of the breadcrumb.
      $variables['breadcrumb'] = \array_merge($new_items,
        (array) $variables['breadcrumb']);
      // Alter the number of segments in the breadcrumb.
      $variables['segments_quantity'] += $i;
    }
  }
}
