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

  // Get total numbers of elements for the pager.
  $pager_total_items = _pager_get_total_items($variables);

  // Syntax shortcut.
  $items = &$variables['pager']['pager']['#items'];

  // Change the display order between pager_first and pager_previous
  // to match ECL.
  $first_item_key = _pager_get_item_keys($items, 'pager_first');
  if (!empty($first_item_key)) {
    $previous_item_key = _pager_get_item_keys($items, 'pager_previous');
    // Get previous link.
    $pager_previous = _pager_get_items_by_pager_type($items, 'pager_previous');
    // Change the text.
    $items[$first_item_key[0]]['pager_item']['#text'] = 1;
    // Remove the previous pager link.
    unset($items[$previous_item_key[0]]);
    // Move it to the beginning items list.
    $items = array_merge($pager_previous, $items);

    // Case the pager_first is shown do not display pager_1.
    $pager_links = _pager_get_item_keys($items, 'pager_link');
    $pager_first = _pager_get_item_keys($items, 'pager_first');

    if ($items[$pager_first[0]]['pager_item']['#text'] === $items[$pager_links[0]]['pager_item']['#text']) {
      unset($items[$pager_links[0]]);
    }
  }

  $ellipsis = NULL;

  // Remove all the ellipsis from the items array.
  $pager_ellipsis = _pager_get_item_keys($items, 'pager_ellipsis');
  foreach ($pager_ellipsis as $key) {
    if (isset($items[$key])) {
      $ellipsis = $items[$key];
    }
    unset($items[$key]);
  }

  // Logic to append first ELLIPSIS.
  // Case the pager_first is shown do not display pager_1.
  $pager_links = _pager_get_item_keys($items, 'pager_link');
  $pager_first = _pager_get_item_keys($items, 'pager_first');
  $pager_current = _pager_get_item_keys($items, 'pager_current');
  if ($ellipsis !== NULL && !empty($pager_first) && !empty($pager_links)) {
    // TRUE if the pager first page is different from the first pager link page.
    $condition1 = $items[$pager_links[0]]['#pager_page'] !== $items[$pager_first[0]]['#pager_page'] + 1;
    // TRUE if the pager first is different from the current pager link page.
    $condition2 = $items[$pager_current[0]]['#pager_page'] !== $items[$pager_first[0]]['#pager_page'] + 1;
    if ($condition1 && $condition2) {
      array_splice($items, $pager_first[0] + 1, 0, array($ellipsis));
    }
  }

  // Logic for second ELLIPSIS.
  $pager_links = _pager_get_item_keys($items, 'pager_link');
  $pager_last = _pager_get_item_keys($items, 'pager_last');
  $pager_current = _pager_get_items_by_pager_type($items, 'pager_current');
  if (!empty($pager_last) && !empty($pager_links)) {
    $end = end($pager_links);
    if ($items[$end]['#pager_page'] + 1 < $items[$pager_last[0]]['#pager_page']) {
      $offset = ($pager_current[0]['#pager_page'] < 6) ? 2 : 1;
      array_splice($items, $pager_last[0] - $offset, 0, array($ellipsis));
    }
  }

  // Change the display order between pager_last and pager_next to match ECL.
  $last_item_key = _pager_get_item_keys($items, 'pager_last');
  $next_item_key = _pager_get_item_keys($items, 'pager_next');
  if (!empty($last_item_key) && !empty($next_item_key)) {
    $pager_next = _pager_get_items_by_pager_type($items, 'pager_next');
    $items[$last_item_key[0]]['pager_item']['#text'] = $pager_total_items;
    // Avoiding duplicated next.
    unset($items[$next_item_key[0]]);
    // Adding next to the end.
    $items[] = $pager_next[0];
  }

  $items = array_values($items);

  // Remove duplicates last link and last pager.
  $pager_links = _pager_get_item_keys($items, 'pager_link');
  $pager_last = _pager_get_item_keys($items, 'pager_last');
  if (!empty($pager_links) && !empty($pager_last)) {
    $end = end($pager_links);
    if ($items[$pager_last[0]]['#pager_page'] === $items[$end]['#pager_page']) {
      // Remove page last.
      $pager_last = _pager_get_item_keys($items, 'pager_last');
      unset($items[$pager_last[0]]);
    }
  }

  $pager_last = _pager_get_item_keys($items, 'pager_last');
  $pager_current = _pager_get_item_keys($items, 'pager_current');
  $delta = 0;
  if (!empty($pager_last)) {
    $delta = $items[$pager_last[0]]['#pager_page'] - $items[$pager_current[0]]['#pager_page'];
  }

  // If the current page is 5 elements or less before the end.
  if ($delta < 4 && $pager_total_items > 10) {
    $next_item_key = _pager_get_item_keys($items, 'pager_next');
    if (!empty($next_item_key)) {
      unset($items[$next_item_key[0]]);
    }

    $pager_current = _pager_get_item_keys($items, 'pager_current');
    $current = $items[$pager_current[0]]['#pager_page'];

    foreach ($pager_links as $key) {
      if ($items[$key]['#pager_page'] < $current - 4) {
        unset($items[$key]);
      }
    }
  }

  $links = array();
  $has_ellipsis = FALSE;
  // This loops does 2 things.
  // 1) It saves an array with keys that are either pager_current or pager_link.
  // 2) It checks if the pager has an ellipsis and set a variable accordingly.
  foreach ($items as $key => $item) {
    $base = $item['#pager_item_type'];

    if ($base === 'pager_current') {
      $links[$key] = $base;
    }

    if ($base === 'pager_link') {
      $links[$key] = $base;
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
  if ($has_ellipsis === TRUE && ((count($links) - $index_current) < 4)) {
    // In that case we delete the Next link.
    $next_item_key = _pager_get_item_keys($items, 'pager_next');
    unset($items[$next_item_key[0]]);

    // Ensure that there is only 4 elements before the 'current' element.
    $links = array_slice($links, $index_current - 4, 4);

    // Remove the elements, and break as soon as we reach the current element.
    foreach ($items as $key => $item) {
      $base = $item['#pager_item_type'];

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

  // Add classes required by ECL to the remaining elements.
  _pager_add_ecl_classes($items);
}

/**
 * Append some required ECL classes.
 *
 * @param array $items
 *   A list of pager items.
 */
function _pager_add_ecl_classes(array &$items) {
  foreach ($items as $key => &$item) {
    $item_type = $item['#pager_item_type'];

    $item['#attributes']['class'][] = 'ecl-pager__item';
    $item['pager_item']['#attributes']['class'][] = 'ecl-pager__link';

    $classMap = array(
      'pager_first' => 'first',
      'pager_previous' => 'previous',
      'pager_last' => 'last',
      'pager_next' => 'next',
      'pager_current' => 'current',
      'pager_ellipsis' => 'ellipsis',
    );

    if (isset($classMap[$item_type])) {
      $item['#attributes']['class'][] = 'ecl-pager__item--' . $classMap[$item_type];
    }
  }
}

/**
 * Get the pager items by pager type.
 *
 * @param array $items
 *   The list of pager items.
 * @param string $pager_type
 *   The pager type designation: pager_first, pager_last, etc.
 *
 * @return array
 *   A list of items belonging to the same pager type.
 */
function _pager_get_items_by_pager_type(array $items, $pager_type) {
  return array_values(
    array_intersect_key(
      $items,
      array_flip(_pager_get_item_keys($items, $pager_type))
    )
  );
}

/**
 * Get the item key.
 *
 * @param array $items
 *   The entire pager structure.
 * @param string $pager_type
 *   The pager type designation: pager_first, pager_last, etc.
 *
 * @return array
 *   The array with $pager_type key within $items.
 */
function _pager_get_item_keys(array $items, $pager_type) {
  return array_keys(
    array_filter(
      $items,
      function ($item) use ($pager_type) {
        return $item['#pager_item_type'] === $pager_type;
      }
    )
  );
}

/**
 * The total number of pager items.
 *
 * @param array $variables
 *   The callback available elements.
 *
 * @return int
 *   The total number of pager items.
 */
function _pager_get_total_items(array &$variables) {
  // Compute the total number of element in this particular pager.
  $element = $variables['element'];
  $pager_total = isset($GLOBALS['pager_total']) ?
    $GLOBALS['pager_total'] :
    array();

  if (isset($variables['pager_total']) && $variables['pager_total'] !== NULL) {
    $pager_total = $variables['pager_total'];
  }

  return (int) $pager_total[$element];
}
