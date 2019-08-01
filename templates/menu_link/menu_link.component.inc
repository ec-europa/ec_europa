<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link(array &$variables, $hook) {
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-link';
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-link--standalone';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__main_menu(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-navigation-menu__item');
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-navigation-menu__link';

  $link = $variables['element']['#original_link'];

  if ($link['in_active_trail']) {
    if ($link['depth'] === 1) {
      $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-navigation-menu__item--active');
    }
    else {
      $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-navigation-menu__link--active';
    }
  }

  // If the menu item has a submenu and has a depth of 1,
  // render it as a button.
  if (!empty($variables['sub_menu'])) {
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['id'][] = 'nav-menu-expandable-label-' . $link['mlid'];
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['aria-controls'][] = 'nav-menu-expandable-group-' . $link['mlid'];
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['aria-expanded'][] = 'false';
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['aria-haspopup'][] = 'true';
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__user_menu(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-navigation-list__item');

  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-navigation-list__link';
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-link';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_service_tools(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-list-inline__item');
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_service_links(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-list-inline__item');
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'] = \array_diff(
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'],
    array('ecl-link--standalone')
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_service_links__footer(array &$variables, $hook) {
  $variables = \_ec_europa_menu_link_footer_alter($variables);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_social_media(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-list-inline__item');
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'] = \array_diff(
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'],
    array('ecl-link--standalone')
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_social_media__footer(array &$variables, $hook) {
  $variables = \_ec_europa_menu_link_footer_alter($variables);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_inst_links(array &$variables, $hook) {
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'] = \array_diff(
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'],
    array('ecl-link--standalone')
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_inst_links__footer(array &$variables, $hook) {
  $variables = \_ec_europa_menu_link_footer_alter($variables);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_site_links(array &$variables, $hook) {
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'] = \array_diff(
    $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'],
    array('ecl-link--standalone')
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__nexteuropa_site_social_media(array &$variables, $hook) {
  $variables = \_ec_europa_menu_link_footer_alter($variables);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__nexteuropa_site_custom_links(array &$variables, $hook) {
  $variables = \_ec_europa_menu_link_footer_alter($variables);
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_link__menu_nexteuropa_site_links__footer(array &$variables, $hook) {
  $variables = \_ec_europa_menu_link_footer_alter($variables);
}

/**
 * Alter specific menu link for the footer.
 *
 * @param array $variables
 *   The array of variables.
 *
 * @return array
 *   The array of variables.
 */
function _ec_europa_menu_link_footer_alter(array $variables) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-footer__menu-item');
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-footer__link';
  $variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'][] = 'ecl-link--inverted';

  $classes = &$variables[$variables['base_hook']][$variables['base_hook']]['#options']['attributes']['class'];

  if (\in_array('ecl-icon', $classes, TRUE)) {
    $classes[] = 'ecl-footer__social-icon';
  }

  return $variables;
}
