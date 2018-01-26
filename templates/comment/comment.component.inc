<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_comment(&$variables, $hook) {
  $comment = $variables['elements']['#comment'];
  $variables['created'] = format_date($comment->created, 'ec_date');
  $variables['title'] = check_plain($comment->subject);

  $variables['content']['links']['#attributes']['class'][] = 'ecl-list--inline ecl-comment__operations';

  array_walk($variables['content']['links']['comment']['#links'], function (&$link) {
    $link['attributes']['class'] = array('ecl-comment__' . $link['title']);
  });

  $variables['path'] = url(
    current_path(),
    array(
      'fragment' => 'comment-' . $comment->cid,
      'options' => array('absolute' => TRUE),
    )
  );
}
