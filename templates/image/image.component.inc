<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 *
 * @todo We need to investigate if there is a need to maintain this function
 * to add the class img-responsive, because it's confirmed that we already have
 * it in some cases.
 */
function europa_preprocess_image(&$variables, $hook) {
  // Fix issue between print module and bootstrap theme, print module put a
  // string instead of an array in $variables['attributes']['class'].
  if (theme_get_setting('bootstrap_image_responsive')) {
    if (isset($variables['attributes']['class'])
      && is_array($variables['attributes']['class'])
    ) {
      // This avoids having the class .img-responsive repeated in the element.
      if (!in_array('img-responsive', $variables['attributes']['class'])) {
        $variables['attributes']['class'][] = 'img-responsive';
      }
    }
    else {
      $variables['attributes']['class'] = !empty($variables['attributes']['class'])
        ? $variables['attributes']['class'] . ' img-responsive' : 'img-responsive';
    }
  }
}
