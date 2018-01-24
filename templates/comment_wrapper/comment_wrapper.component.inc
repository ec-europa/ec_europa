<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_comment_wrapper(&$variables, $hook) {
  $form = &$variables['content']['comment_form'];
  $form['actions']['submit']['#value'] = t('Send');
  unset($form['author']);

  $comments = array_filter($variables['content']['comments'], function ($index) use (&$variables) {
    if (is_numeric($index)) {
      unset($variables['content']['comments'][$index]);
      return TRUE;
    }
  }, ARRAY_FILTER_USE_KEY);

  $variables['content']['comments']['comments'] = array(
    '#theme' => 'item_list',
    '#wrapper' => FALSE,
    '#attributes' => array(
      'class' => array(
        'ecl-listing',
      ),
    ),
    '#items' => array_map(function ($comment) {
      return array(
        'class' => array(
          'ecl-list-item',
          'ecl-u-pv-s',
        ),
        'data' => $comment,
      );
    }, $comments),
  );
}
