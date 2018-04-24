<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function ec_europa_form_alter(array &$form, array &$form_state, $form_id) {
  if (isset($form['views_bulk_operations'])) {
    foreach (element_children($form['views_bulk_operations']) as $child) {
      if ($form['views_bulk_operations'][$child]['#type'] == 'checkbox') {
        $form['views_bulk_operations'][$child]['#title'] = ' ';
      }
    }
  }
}

/**
 * Implements hook_FORM_ID_alter().
 */
function ec_europa_form_search_block_form_alter(array &$form, array &$form_state, $form_id) {
  $form['#attributes']['class'][] = 'search-block';
  $form['search_block_form']['#attributes']['class'][] = 'search-form__textfield form-control';
  $form['actions']['submit']['#attributes']['class'][] = 'btn-search search-form__btn btn btn-primary';
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function ec_europa_form_views_exposed_form_alter(array &$form, array &$form_state, $form_id) {
  // Button value change on all the views exposed forms is due to a
  // design/ux requirement which uses the 'Refine results' label for all the
  // filter forms.
  $form['submit']['#value'] = t('Refine results');
  $form['submit']['#attributes']['class'][] = 'btn-primary';
  $form['submit']['#attributes']['class'][] = 'filters__btn-submit';
  $form['reset']['#attributes']['class'][] = 'filters__btn-reset';
}
