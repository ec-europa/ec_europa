<?php

/**
 * @file
 * html_head.inc
 */

/**
 * Implements hook_html_head_alter().
 */
function europa_html_head_alter(&$head_elements) {
  // Creating favicons links and meta tags for the html header.
  $europa_theme_png_path = base_path() . drupal_get_path('theme', 'europa') . '/images/png/favicon/';
  $elements = [
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '57x57',
        'href' => 'apple-touch-icon-57x57.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '60x60',
        'href' => 'apple-touch-icon-60x60.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '114x114',
        'href' => 'apple-touch-icon-114x114.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '120x120',
        'href' => 'apple-touch-icon-120x120.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '144x144',
        'href' => 'apple-touch-icon-144x144.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '152x152',
        'href' => 'apple-touch-icon-152x152.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'apple-touch-icon',
        'sizes' => '180x180',
        'href' => 'apple-touch-icon-180x180.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '32x32',
        'href' => 'favicon-32x32.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '192x192',
        'href' => 'android-chrome-192x192.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '96x96',
        'href' => 'favicon-96x96.png',
      ],
    ],
    [
      '#tag' => 'link',
      '#attributes' => [
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '16x16',
        'href' => 'favicon-16x16.png',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'msapplication-TileColor',
        'content' => '#034ea1',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'msapplication-TileImage',
        'content' => $europa_theme_png_path . 'mstile-144x144.png',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'theme-color',
        'content' => '#034ea1',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'msapplication-square70x70logo',
        'content' => $europa_theme_png_path . 'mstile-70x70.png',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'msapplication-square150x150logo',
        'content' => $europa_theme_png_path . 'mstile-150x150.png',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'msapplication-wide310x150logo',
        'content' => $europa_theme_png_path . 'mstile-310x150.png',
      ],
    ],
    [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'msapplication-square310x310logo',
        'content' => $europa_theme_png_path . 'mstile-310x310.png',
      ],
    ],
  ];
  foreach ($elements as $element) {
    $element['#type'] = 'html_tag';
    if (isset($element['#attributes']['href'])) {
      $element['#attributes']['href'] = $europa_theme_png_path . $element['#attributes']['href'];
    }
    $head_elements[] = $element;
  }
}
