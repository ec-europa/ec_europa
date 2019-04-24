<?php

/**
 * @file
 * Contains pager component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_pager(array &$variables, $hook) {
  if (!isset($variables['pager']['pager']['#items'])) {
    return;
  }

  // Add classes required by ECL.
  $variables['pager']['pager']['#attributes']['class'][] = 'ecl-pager';
  $variables['pager']['pager']['#wrapper_attributes']['class'][] = 'ecl-pager__wrapper';

  // Compute the total number of element in this particular pager.
  $element = $variables['element'];
  $pager_total = isset($GLOBALS['pager_total']) ?
    $GLOBALS['pager_total'] :
    array();
  if (isset($variables['pager_total']) && $variables['pager_total'] !== NULL) {
    $pager_total = $variables['pager_total'];
  }
  $pager_total_element = (int) $pager_total[$element];

  // Syntax shortcut.
  $items = &$variables['pager']['pager']['#items'];

  // Append Page on Current pager.
  if ($items['pager_current']['#markup']) {
    $items["pager_current"]["#markup"] =
      '<span class="ecl-pager__item-text">Page</span> ' .
      $items["pager_current"]["#markup"];
  }

  // Update text to use Next instead of next.
  if (isset($items['pager_next']['pager_next'])) {
    $items['pager_next']['pager_next']['#text'] = t('Next ›');
  }

  // Update text to use Previous instead of previous.
  if (isset($items['pager_previous']['pager_previous'])) {
    $items['pager_previous']['pager_previous']['#text'] = t('‹ Previous');
  }

  // Change the display order between pager_first and pager_previous
  // to match ECL.
  if (isset($items['pager_first'])) {
    $previous = $items['pager_previous'];

    $items['pager_first']['pager_first']['#text'] = 1;
    unset($items['pager_previous']);

    $items = array('pager_previous' => $previous)
      + $items;

    // Case the pager_first is shown do not display pager_1.
    if (isset($items['pager_link__1'])) {
      unset($items['pager_link__1']);
    }
  }

  // Case the pager_link__2 is shown do not display pager_ellipsis__2.
  if (isset($items['pager_link__2'])) {
    unset($items['pager_ellipsis__2']);
  }

  // Change the display order between pager_last and pager_next to match ECL.
  if (isset($items['pager_last'])) {
    $next = $items['pager_next'];
    $items['pager_last']['pager_last']['#text'] = $pager_total_element;
    unset($items['pager_next']);
    $items += array('pager_next' => $next);

    // Case the pager_last is shown do not display the last item number.
    $last_page = 'pager_link__' . $pager_total_element;
    if (isset($items[$last_page])) {
      unset($items[$last_page]);
    }
  }

  $links = array();
  $has_ellipsis = FALSE;
  // This loops does 2 things.
  // 1) It saves an array with keys that are either pager_current or pager_link.
  // 2) It checks if the pager has an ellipsis and set a variable accordingly.
  foreach ($items as $key => $item) {
    $base = atomium_get_base_hook($key);

    if ($base === 'pager_current') {
      $links[$key] = $key;
    }

    if ($base === 'pager_link') {
      $links[$key] = $key;
    }

    if ($base === 'pager_ellipsis') {
      $has_ellipsis = TRUE;
    }
  }

  // Find the index of the current element.
  $index_current = array_search(
    'pager_current',
    array_keys($links),
    TRUE
  );

  // If there is an ellipsis and if the current element is within 4 elements
  // before the end of the links array.
  if ((count($links) - $index_current < 4) && $has_ellipsis === TRUE) {
    // In that case we delete the Next link.
    unset($items['pager_next']);

    // Ensure that there is only 4 elements before the 'current' element.
    $links = array_slice($links, $index_current - 4, 4);

    // Remove the elements, and break as soon as we reach the current element.
    foreach (array_keys($items) as $key) {
      $base = atomium_get_base_hook($key);

      if ($base === 'pager_current') {
        break;
      }

      if ($base === 'pager_link') {
        if (!isset($links[$key])) {
          unset($items[$key]);
        }
      }
    }
  }

  // Add classes required by ECL to remaining elements.
  foreach ($items as $key => &$item) {
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
