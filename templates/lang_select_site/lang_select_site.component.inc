<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_lang_select_site() {
  global $language;

  return array(
    'label' => 'Site language selector',
    'description' => 'Site language selector.',
    'dependencies' => array('nexteuropa_multilingual'),
    'preview' => array(
      'url' => '#',
      'code' => isset($language->prefix) ? $language->prefix : $language->language,
      'label' => $language->native,
      'attributes' => array(),
    ),
  );
}

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_lang_select_site(array $existing, $type, $theme, $path) {
  return array(
    'lang_select_site' => array(
      'template' => 'lang-select-site',
      'variables' => array(
        'url' => NULL,
        'code' => NULL,
        'label' => NULL,
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_lang_select_site(array &$variables, $hook) {
  $language_current = $GLOBALS['language_content'];
  $languages_list = \language_list('enabled');
  $variables['code'] = $language_current->language;
  $variables['label'] = $language_current->name;

  $variables['url'] = \url(
    'language-selector/site-language',
    array(
      'html' => TRUE,
      'query' => array(
        \drupal_get_destination(),
      ),
    )
  );

  // Build the list of links.
  $languages = \array_map(static function ($language) use ($variables) {
    return array(
      '#theme' => \_atomium_extend_theme_hook('link', $variables['theme_hook_original']),
      '#text' => $language->name,
      '#path' => \current_path(),
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
  $languages = \array_map(static function ($language) use ($language_current, $variables) {
    if ($language_current->language === $language['#language']->language) {
      $language['#options']['attributes']['class'] = \array_merge(
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
          '#theme' => \_atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
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
  $languages = \array_chunk(
    $languages,
    \round(\count($languages) / 2)
  );

  // Wrap each column with a container.
  \array_walk($languages, static function (&$language, $index) use ($variables) {
    $language['#theme'] = \_atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']);
    $language['#tag'] = 'div';
    $language['#attributes'] = array(
      'class' => array(
        'column-' . $index,
        'ecl-col-md-6',
      ),
    );
  });

  $variables['languages'] = $languages;
}
