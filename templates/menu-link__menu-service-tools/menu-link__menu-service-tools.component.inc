<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Override theme_menu_link().
 */
function europa_menu_link__menu_service_tools(&$variables) {
  return _europa_menu_link__footer($variables);
}
