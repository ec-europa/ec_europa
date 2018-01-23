<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_language_selector_site_language_list(&$variables, $hook) {
  $language_current = $GLOBALS['language'];
  $languages_list = language_list('enabled');

  $destination = isset($_GET['destination']) ? $_GET['destination'] : '<front>';
  $path_components = drupal_parse_url(url($destination));

  // Build the list of links.
  $languages = array_map(function ($language) use ($variables, $path_components) {
    return array(
      '#theme' => array('link__' . $variables['theme_hook_original']),
      '#text' => $language->name,
      '#path' => $path_components['path'],
      '#options' => array(
        'attributes' => array(
          'class' => array(
            'ecl-button',
            'ecl-button--default',
            'ecl-button--block',
            'ecl-language-list__button',
          ),
          'lang' => $language->language,
          'hreflang' => $language->language,
          'rel' => 'alternate',
        ),
        'html' => FALSE,
      ),
      '#language' => $language,
    );
  }, $languages_list[1]);

  // Update current language's link only.
  $languages = array_map(function ($language) use ($language_current, $variables) {
    if ($language_current->language == $language['#language']->language) {
      $language['#options']['attributes']['class'] = array_merge(
        $language['#options']['attributes']['class'],
        array(
          'ecl-language-list__button--active',
          'ecl-icon',
          'ecl-icon--icon-check',
        )
      );

      $language['#options']['html'] = TRUE;
      $language['#text'] = array(
        array(
          '#theme' => 'html_tag__' . $variables['theme_hook_original'],
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array(
              'ecl-icon',
              'ecl-icon--check',
              'ecl-u-f-r',
            ),
          ),
        ),
        array(
          '#markup' => $language['#text'],
        ),
      );
    }

    return $language;
  }, $languages);

  // Split the array in 2 columns.
  $languages = array_chunk(
    $languages,
    round(count($languages) / 2)
  );

  // Wrap each column with a container.
  array_walk($languages, function (&$language, $index) use ($variables) {
    $language['#theme'] = array('html_tag__' . $variables['theme_hook_original']);
    $language['#tag'] = 'div';
    $language['#attributes'] = array(
      'class' => array(
        'column-' . $index,
        'ecl-col-md-6',
      ),
    );
  });

  $variables[$hook] = array(
    $hook => $languages,
  );
}
