<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__secondary(array &$variables, $hook) {
  // TODO: is this still necessary ?
  $variables['atomium']['attributes']['wrapper']
    ->append('class', array('menu', 'nav', 'navbar-nav', 'secondary'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__main_menu(array &$variables, $hook) {
  if (isset($variables['#tree'])) {
    if ($children = element_children($variables['#tree'])) {
      if ($item = $variables['#tree'][$children[0]]) {
        $menu = menu_load($item['#original_link']['menu_name']);
        $variables['title'] = $menu['title'];

        if (1 == $variables['depth']) {
          $variables['atomium']['attributes']['wrapper']
            ->append('class', 'ecl-navigation-menu__root')
            ->append('id', 'nav-menu-expandable-root');
        }
        else {
          $variables['atomium']['attributes']['wrapper']
            ->append('id', 'nav-menu-expandable-group-' . $item['#original_link']['plid']);
          $variables['atomium']['attributes']['wrapper']
            ->append('class', 'ecl-navigation-menu__group');
        }
      }
    }
  }

  if (1 == $variables['depth']) {
    $variables['atomium']['attributes']['wrapper']->append('aria-hidden', 'true');
  }

}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__user_menu(array &$variables, $hook) {
  global $user;
  $variables['logged_in_user'] = '';
  if (!user_is_anonymous()) {
    $variables['logged_in_user'] = t('Logged in as %username', array('%username' => format_username($user)));
  }
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-navigation-list ecl-navigation-list--small');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_service_links(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list--inline'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_service_tools(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list--inline'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_social_media(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list--inline'));
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_inst_links(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-footer__menu');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__menu_nexteuropa_site_links(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-footer__menu');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__nexteuropa_site_social_media(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append(
    'class',
    array(
      'ecl-footer__menu',
      'ecl-list--inline',
      'ecl-footer__social-links',
    )
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_tree__nexteuropa_site_custom_links(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('ecl-footer__menu', 'ecl-list--unstyled'));
}
