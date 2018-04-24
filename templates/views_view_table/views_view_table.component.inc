<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_views_view_table(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', $variables['classes_array']);

  $i = 0;
  foreach ($variables['header'] as $rowid => $row) {
    if (isset($variables['header_classes'][$rowid])) {
      $variables['atomium']['attributes']['header-cell-0-' . $i]->append('class', $variables['header_classes'][$rowid]);
    }
    $i++;
  }

  foreach ($variables['rows'] as $rowid => $row) {
    if (isset($variables['row_classes'][$rowid])) {
      $variables['atomium']['attributes']['body-row-' . $rowid]->append('class', $variables['row_classes'][$rowid]);
    }
  }

  $variables['table'] = array(
    '#theme' => 'table',
    '#rows' => $variables['rows'],
    '#header' => $variables['header'],
    '#caption' => $variables['caption'],
    '#atomium' => $variables['atomium'],
  );

  _atomium_extend_theme_property(
    $variables['table'],
    array($variables['theme_hook_original'])
  );
}
