<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__main_menu(&$variables, $hook) {
  if (isset($variables['#tree'])) {
    $children = element_children($variables['#tree']);
    if (isset($children[0])) {
      $item = $variables['#tree'][$children[0]];
      if ($item) {
        $original_link = $item['#original_link'];
        $menu = menu_load($original_link['menu_name']);
        $variables['title'] = $menu['title'];
        if ($variables['depth'] > 1) {
          $variables['atomium']['attributes']['wrapper']
            ->append('id', 'nav-menu-expandable-group-' . $original_link['plid']);
        }
        if ($variables['depth'] == 1) {
          $variables['atomium']['attributes']['wrapper']
            ->append('class', 'ecl-navigation-menu__root')
            ->append('id', 'nav-menu-expandable-root');
        }
        else {
          $variables['atomium']['attributes']['wrapper']
            ->append('class', 'ecl-navigation-menu__group');
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__user_menu(&$variables, $hook) {
  global $user;
  $variables['logged_in_user'] = '';
  if (!user_is_anonymous()) {
    $variables['logged_in_user'] = t('Logged in as %username', array('%username' => format_username($user)));
  }
  $variables['atomium']['attributes']['wrapper']->append('class', 'site-user-menu__list');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_service_links(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list-inline'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_service_tools(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list-inline'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_social_media(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list-inline'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_inst_links(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-footer__menu');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_site_links(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-footer__menu');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__secondary(&$variables, $hook) {
  // TODO: is this still necessary ?
  $variables['atomium']['attributes']['wrapper']
    ->append('class', array('menu', 'nav', 'navbar-nav', 'secondary'));
}
