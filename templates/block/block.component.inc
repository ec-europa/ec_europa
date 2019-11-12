<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_block() {
  return array(
    'label' => 'Block',
    'description' => 'Blocks.',
    'dependencies' => array('block'),
    'disable' => TRUE,
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_block(array $form, array &$form_state) {
  global $theme_key;

  // List of blocks we want to preview. Format: [module]:[delta].
  $block_whitelist = array(
    'system:main-menu',
    'system:user-menu',
  );

  module_load_include('inc', 'block', 'block.admin');
  $blocks = block_admin_display_prepare_blocks($theme_key);

  foreach ($blocks as $block) {
    $block_id = $block['module'] . ':' . $block['delta'];

    if (!\in_array($block_id, $block_whitelist, TRUE)) {
      continue;
    }

    $form['blocks'][] = array(
      '#type' => 'fieldset',
      '#title' => \sprintf('Block ([module]:[delta]) (%s)', $block_id),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      'content' => _atomium_block_get_render_array($block['module'], $block['delta']),
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function ec_europa_preprocess_block(array &$variables, $hook) {
  $block = $variables['block'];

  switch ($block->delta) {
    case 'nexteuropa_feedback':
      $variables['atomium']['attributes']['wrapper']->append('class', 'block--full-width');

      break;

    case 'menu-nexteuropa-site-links':
    case 'menu-nexteuropa-social-media':
    case 'menu-nexteuropa-inst-links':
      $variables['title'] = $block->subject;
      $variables['atomium']['attributes']['title']->append('class', array('ecl-heading', 'ecl-heading--h4', 'ecl-footer__column-title'));
      $block->subject = '';

      break;

    case 'menu-nexteuropa-service-links':
      $variables['title'] = '';
      $variables['atomium']['attributes']['title']->append('class', array('ecl-h4', 'ecl-footer__title'));
      $block->subject = '';

      break;

    case 'views_related_links':
      $variables['atomium']['attributes']['wrapper']->append('class', 'link-block');
      $variables['atomium']['attributes']['title']->append('class', 'link-block__title');

      break;

    case 'language_selector_site':
      $variables['lang_code'] = $variables['elements']['code']['#markup'];
      $variables['lang_name'] = $variables['elements']['label']['#markup'];
      $variables['link'] = url('splash') . '?' . drupal_get_destination()['destination'];
      $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-lang-select-sites');

      break;

    case 'inline_navigation':
      $variables['atomium']['attributes']['wrapper']->append('class', 'inpage-nav__wrapper');
      $variables['atomium']['attributes']['title']->append('class', 'inpage-nav__block-title');

      break;
  }

  // Page-level language switcher.
  if (isset($block->bid) && $block->bid === 'language_selector_page-language_selector_page') {
    global $language;

    // selectify.js is the library to convert between ul and select.
    drupal_add_js(drupal_get_path('theme', 'ec_europa') . '/assets/scripts/selectify.js');
    drupal_add_js(drupal_get_path('theme', 'ec_europa') . '/assets/scripts/components/lang-switcher.js');

    // Initialize variables.
    $not_available = '';
    $served = '';
    $other = '';

    if (!empty($variables['elements']['not_available']['#markup'])) {
      $not_available = '<li class="lang-select-page__option lang-select-page__unavailable">' . $variables['elements']['not_available']['#markup']->native . '</li>';
    }

    if (!empty($variables['elements']['served']['#markup'])) {
      $served = '<li class="lang-select-page__option is-selected">' . $variables['elements']['served']['#markup']->native . '</li>';
    }

    if (!empty($variables['elements']['other']['#markup'])) {
      foreach ($variables['elements']['other']['#markup'] as $code => $lang) {
        $options = array();
        $options['query'] = drupal_get_query_parameters();
        $options['query']['2nd-language'] = $code;
        $options['attributes']['lang'] = $code;
        $options['attributes']['hreflang'] = $code;
        $options['attributes']['rel'] = 'alternate';
        $options['language'] = $language;

        $other .= '<li class="lang-select-page__option lang-select-page__other">' . l($lang->native, current_path(), $options) . '</li>';
      }
    }

    // Add class to block.
    $variables['atomium']['attributes']['wrapper']->append('class', array('lang-select-page', 'lang-select-page--transparent'));

    // Add content to block.
    $content = "<span class='lang-select-page__icon icon icon--generic-lang'></span>";
    $content .= "<ul class='lang-select-page__list'>" . $not_available . $served . $other . '</ul>';

    $variables['content'] = $content;
  }

  // Site-level language switcher.
  if (isset($block->bid) && $block->bid === 'language_selector_site-language_selector_site') {
    // Add the js to make it function.
    drupal_add_js(drupal_get_path('theme', 'ec_europa') . '/assets/scripts/components/lang-select-site.js');
  }

  $variables['atomium']['attributes']['title']->append('class', 'block__title');

  if (isset($block->bid)) {
    // Check if the block is a exposed form.
    // This is checked by looking at the $block->bid which in case
    // of views exposed filters, always contains 'views--exp-' string.
    if (\strpos($block->bid, 'views--exp-') !== FALSE) {
      if (isset($block->context) && $context = context_load($block->context)) {
        // If our block is the first, we set the subject. This way, if we expose
        // a second block for the same view, we will not duplicate the title.
        if (\array_search($block->bid, \array_keys($context->reactions['block']['blocks']), TRUE) === 0) {
          $variables['atomium']['attributes']['wrapper']->append('class', 'filters');
          $variables['atomium']['attributes']['title']->append('class', 'filters__title');

          $block->subject = t('Refine results');

          // Passing block id to Drupal.settings in order to pass it through
          // data attribute in the collapsible panel.
          drupal_add_js(array('ec_europa' => array('exposedBlockId' => $variables['block_html_id'])), 'setting');

          // Adding filters.js file.
          drupal_add_js(drupal_get_path('theme', 'ec_europa') . '/assets/scripts/components/filters.js');
        }
      }
    }
  }

  $variables['atomium']['attributes']['content']->append('class', 'block__content');
  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'ecl-clearfix')
    ->append('id', $variables['block_html_id']);
}
