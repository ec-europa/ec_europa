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

  $links = &$variables['content']['links'];
  foreach ($links['comment']['#links'] as &$link) {
    $class = 'ecl-comment__' . $link['title'];
    $link['attributes']['class'] = array($class);
  }

  $variables['path'] = url(
    current_path(),
    array(
      'fragment' => 'comment-' . $comment->cid,
      'options' => array('absolute' => TRUE),
    )
  );
}
