<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_menu_local_task(array &$variables, $hook) {
  // Add the css class to the "li".
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-navigation-list__item');

  // Add css classes to the link itself.
  $task_link = &$variables['menu_local_task']['menu_local_task'];
  $task_link['#options']['attributes']['class'][] = 'ecl-link';

  if (!empty($variables['active'])) {
    $task_link['#options']['attributes']['class'][] = 'ecl-navigation-list__link--active';
  }
  $task_link['#options']['attributes']['class'][] = 'ecl-navigation-list__link';
}
