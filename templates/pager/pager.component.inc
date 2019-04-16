<?php

/**
 * @file
 * Contains pager component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_pager(array &$variables, $hook) {
  $variables['pager']['pager']['#attributes']['class'][] = 'ecl-pager';
  $variables['pager']['pager']['#wrapper_attributes']['class'][] = 'ecl-pager__wrapper';

  if (isset($variables['pager']['pager']['#items']['pager_next']['pager_next'])) {
    $variables['pager']['pager']['#items']['pager_next']['pager_next']['#text'] = t('Next ›');
  }

  if (isset($variables['pager']['pager']['#items']['pager_previous']['pager_previous'])) {
    $variables['pager']['pager']['#items']['pager_previous']['pager_previous']['#text'] = t('‹ Previous');
  }

  if (isset($variables['pager']['pager']['#items']['pager_first'])) {
    $previous = $variables['pager']['pager']['#items']['pager_previous'];

    $variables['pager']['pager']['#items']['pager_first']['pager_first']['#text'] = 1;
    unset($variables['pager']['pager']['#items']['pager_previous']);

    $variables['pager']['pager']['#items'] = array('pager_previous' => $previous)
      + $variables['pager']['pager']['#items'];

    // Case the pager_first is shown do not display pager_1.
    if (isset($variables['pager']['pager']['#items']['pager_link__1'])) {
      unset($variables['pager']['pager']['#items']['pager_link__1']);
    }
  }

  if (isset($variables['pager']['pager']['#items']['pager_last'])) {
    $next = $variables['pager']['pager']['#items']['pager_next'];
    $variables['pager']['pager']['#items']['pager_last']['pager_last']['#text'] = (int) $GLOBALS['pager_total'][0];
    unset($variables['pager']['pager']['#items']['pager_next']);
    $variables['pager']['pager']['#items'] += array('pager_next' => $next);

    // Case the pager_last is shown do not display the last item number.
    $last_page = 'pager_link__' . $variables['pager_total'][0];
    if (isset($variables['pager']['pager']['#items'][$last_page])) {
      unset($variables['pager']['pager']['#items'][$last_page]);
    }
  }

  foreach ($variables['pager']['pager']['#items'] as $key => &$item) {
    $base = atomium_get_base_hook($key);

    $item['#attributes']['class'][] = 'ecl-pager__item';
    $item[$base]['#attributes']['class'][] = 'ecl-pager__link';

    $classMap = array(
      'pager_first' => 'first',
      'pager_previous' => 'previous',
      'pager_last' => 'last',
      'pager_next' => 'next',
      'pager_current' => 'current',
      'pager_ellipsis' => 'ellipsis',
    );

    if (isset($classMap[$base])) {
      $item['#attributes']['class'][] = 'ecl-pager__item--' . $classMap[$base];
    }
  }
}
