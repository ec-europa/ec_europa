<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_site_header() {
  return array(
    'site_header' => array(
      'template' => 'site-header',
      'variables' => array(
        'site_switcher' => array(
          '#theme' => array('site_switcher'),
          '#attributes' => array(
            'class' => array('ecl-site-switcher--header'),
          ),
        ),
        'logo' => array(
          '#theme' => array('logo'),
          '#title' => t('Home - European Commission'),
          '#attributes' => array(
            'class' => array('ecl-site-header__logo', 'ecl-logo--logotype'),
          ),
        ),
        'lang_select_site' => array(
          '#theme' => array('lang_select_site'),
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__lang-select-sites',
            ),
          ),
        ),
        'search_bar' => array(
          '#theme' => array('search_bar'),
          '#attributes' => array(
            'class' => array(
              'ecl-site-header__search',
            ),
          ),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_site_header() {
  return array(
    'label' => 'Site Header',
    'description' => 'Site header.',
    'preview' => array(),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_site_header(&$variables, $hook) {
  $variables['#atomium_recursive'] = TRUE;
  $block = block_load('system', 'user-menu');

  $variables['menu'] = _block_get_renderable_array(_block_render_blocks(array($block)));

  $variables['menu']['system_user-menu']['#theme_wrappers'] = array_map(function ($item) use ($variables, $block) {
    return str_replace(
      '-',
      '_',
      sprintf(
        '%s__%s__%s',
        $item,
        $block->module,
        $block->delta
      )
    );
  }, $variables['menu']['system_user-menu']['#theme_wrappers']);
}
