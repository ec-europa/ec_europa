<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function europa_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['views_bulk_operations'])) {
    $children = element_children($form['views_bulk_operations']);
    foreach ($children as $child) {
      if ($form['views_bulk_operations'][$child]['#type'] == 'checkbox') {
        $form['views_bulk_operations'][$child]['#title'] = ' ';
      }
    }
  }
}
