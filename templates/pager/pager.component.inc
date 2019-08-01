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
  $pager_total_items = \_pager_get_total_items($variables);

  // Syntax shortcut.
  $items = &$variables['pager']['pager']['#items'];

  $pager_curr_key = \_pager_get_item_keys($items, 'pager_current');
  $pager_curr =
    isset($pager_curr_key[0], $items[$pager_curr_key[0]]) ?
    $items[$pager_curr_key[0]]['#pager_i'] :
    NULL;

  foreach ($items as $k => $item) {
    if ($items[$k]['#pager_item_type'] !== 'pager_current' && $pager_curr === $items[$k]['#pager_i']) {
      \hide($items[$k]['pager_item']);
    }
  }

  $items = \array_values($items);
  $pager_links = \_pager_get_item_keys($items, 'pager_link');

  // PART I: Change the display order between pager_first and pager_previous
  // to match ECL, set first page text = 1, and remove duplicated items.
  $first_item_key = \_pager_get_item_keys($items, 'pager_first');

  if (!empty($first_item_key)) {
    $previous_item_key = \_pager_get_item_keys($items, 'pager_previous');

    // Get previous link.
    $pager_previous = \_pager_get_items_by_pager_type($items, 'pager_previous');

    // Change the text.
    $items[$first_item_key[0]]['pager_item']['#text'] = 1;

    // Remove the previous pager link.
    unset($items[$previous_item_key[0]]);

    // Move it to the beginning items list.
    $items = \array_merge($pager_previous, $items);

    // Case the pager_first is shown do not display pager_1.
    \_manage_pager_page1_and_first_page($pager_links, $items);
  }

  // PART II ELLIPSIS.
  $ellipsis = NULL;
  // Remove all the ellipsis from the items array.
  $pager_ellipsis_keys = \_pager_get_item_keys($items, 'pager_ellipsis');

  foreach ($pager_ellipsis_keys as $key) {
    if (isset($items[$key])) {
      $ellipsis = $items[$key];
    }
    unset($items[$key]);
  }
  // Display first and second ellipsis.
  if ($ellipsis) {
    \_manage_pager_ellipsis($ellipsis, $items);

    // PART III SWAP LAST AND NEXT.
    \_manage_pager_last_and_next_page($pager_total_items, $items);

    // PART IV Check whether to display pager last.
    \_manage_pager_last_link_and_last_page($items);

    // PART V: Manage the links in between ellipsis.
    \_manage_pager_links_between_ellipsis($pager_total_items, $items);

    // Add classes required by ECL to the remaining elements.
    \_pager_add_ecl_classes($items);
  }
}

/**
 * Compute pager ellipsis.
 *
 * @param array $ellipsis
 *   The list of current pager items.
 * @param array $items
 *   The list of current pager items.
 */
function _manage_pager_ellipsis(array &$ellipsis, array &$items) {
  // Logic to append first ELLIPSIS.
  // Case the pager_first is shown do not display pager_1.
  $pager_links = \_pager_get_item_keys($items, 'pager_link');
  $pager_first = \_pager_get_item_keys($items, 'pager_first');
  $pager_current = \_pager_get_item_keys($items, 'pager_current');

  // In case of ellipsis, pager_first and pager_links.
  if ($ellipsis !== NULL && !empty($pager_first) && !empty($pager_links)) {
    // TRUE if the pager first page is different from the first pager link page.
    $condition1 = $items[$pager_links[0]]['#pager_page'] !== $items[$pager_first[0]]['#pager_page'] + 1;
    // TRUE if the pager current is different from the current pager first page.
    $condition2 = $items[$pager_current[0]]['#pager_page'] !== $items[$pager_first[0]]['#pager_page'] + 1;
    // Append the ellipsis after the pager_first.
    if ($condition1 && $condition2) {
      \array_splice($items, $pager_first[0] + 1, 0, array($ellipsis));
    }
  }

  // Re-order the items index.
  $items = \array_values($items);

  // Logic for second ELLIPSIS.
  $pager_links = \_pager_get_item_keys($items, 'pager_link');
  $pager_last = \_pager_get_item_keys($items, 'pager_last');
  $pager_current = \_pager_get_items_by_pager_type($items, 'pager_current');

  if (!empty($pager_last) && !empty($pager_links)) {
    $end = \end($pager_links);

    if ($items[$end]['#pager_page'] + 1 < --$items[$pager_last[0]]['#pager_max']) {
      $pager_links = \_pager_get_item_keys($items, 'pager_link');
      $offset = ($pager_current[0]['#pager_page'] < 6) ? $end + 1 : $pager_last[0] - 1;

      \array_splice($items, $offset, 0, array($ellipsis));
    }
  }
}

/**
 * Manage the number of links to display between ellipsis.
 *
 * Eg: "… 3 4 5 6 Page 7 8 9 10 11 …".
 * Eg: "< Previous 1 … 43 44 45 46 Page 47 48 49 50 Next >".
 *
 * @param int $pager_total_items
 *   The pager total number of items.
 * @param array $items
 *   The list of current pager items.
 */
function _manage_pager_links_between_ellipsis(int $pager_total_items, array &$items) {
  $pager_last = \_pager_get_item_keys($items, 'pager_last');
  $pager_current = \_pager_get_item_keys($items, 'pager_current');
  $delta = 0;

  if (!empty($pager_last)) {
    $delta = $items[$pager_last[0]]['#pager_page'] - $items[$pager_current[0]]['#pager_page'];
  }

  // If the current page is 5 elements or less before the end.
  if ($delta < 4 && $pager_total_items > 10) {
    $next_item_key = \_pager_get_item_keys($items, 'pager_next');

    if (!empty($next_item_key) && $items[$next_item_key[0]]['#pager_item_type'] !== 'pager_next') {
      unset($items[$next_item_key[0]]);
    }

    $pager_current = \_pager_get_item_keys($items, 'pager_current');

    if (isset($pager_current[0], $items[$pager_current[0]])) {
      $current = $items[$pager_current[0]]['#pager_page'];
      $pager_links = \_pager_get_item_keys($items, 'pager_link');

      foreach ($pager_links as $key) {
        if (isset($items[$key]) && ($items[$key]['#pager_page'] < ($current - 4))) {
          unset($items[$key]);
        }
      }
    }
  }
}

/**
 * This function compute how and when to display page_1 and page_first.
 *
 * @param array $pager_links
 *   The list of pager links.
 * @param array $items
 *   The list of current pager items.
 */
function _manage_pager_page1_and_first_page(array $pager_links, array &$items) {
  // Case the pager_first is shown do not display pager_1.
  $pager_first = \_pager_get_item_keys($items, 'pager_first');

  if ($items[$pager_first[0]]['pager_item']['#text'] === $items[$pager_links[0]]['pager_item']['#text']) {
    unset($items[$pager_links[0]]);
  }
}

/**
 * This function compute how and when to display last pager_link.
 *
 * Avoiding duplicated pager item (between last link and last pager).
 *
 * @param array $items
 *   The list of current pager items.
 */
function _manage_pager_last_link_and_last_page(array &$items) {
  // In case last item of pager_links is equal to pager_last, do not display it.
  $pager_link_keys = \_pager_get_item_keys($items, 'pager_link');
  $pager_last_key = \_pager_get_item_keys($items, 'pager_last');

  if (empty($pager_last_key) || empty($pager_link_keys)) {
    return;
  }

  $last_link_key = \end($pager_link_keys);

  if ($items[$pager_last_key[0]]['pager_item']['#text'] === $items[$last_link_key]['pager_item']['#text']) {
    unset($items[$last_link_key]);
  }
}

/**
 * Manage pager_last and first, accordingly to ECL.
 *
 * @param int $pager_total_items
 *   The pager total number of items.
 * @param array $items
 *   The list of current pager items.
 */
function _manage_pager_last_and_next_page(int $pager_total_items, array &$items) {
  // Change the display order between pager_last and pager_next to match ECL.
  $last_item_key = \_pager_get_item_keys($items, 'pager_last');
  $next_item_key = \_pager_get_item_keys($items, 'pager_next');

  if (!empty($last_item_key) && !empty($next_item_key)) {
    $pager_next = \_pager_get_items_by_pager_type($items, 'pager_next');
    $items[$last_item_key[0]]['pager_item']['#text'] = $pager_total_items;
    // Avoiding duplicated next.
    unset($items[$next_item_key[0]]);
    // Adding next to the end.
    $items[] = $pager_next[0];
  }
  $items = \array_values($items);
}

/**
 * Append some required ECL classes.
 *
 * @param array $items
 *   A list of pager items.
 */
function _pager_add_ecl_classes(array &$items) {
  foreach ($items as &$item) {
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
  return \array_values(
    \array_intersect_key(
      $items,
      \array_flip(\_pager_get_item_keys($items, $pager_type))
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
  return \array_keys(
    \array_filter(
      $items,
      static function ($item) use ($pager_type) {
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
