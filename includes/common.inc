<?php

/**
 * @file
 * common.inc
 */

/**
 * Get the render array of a block.
 *
 * @param string $module
 *   The module.
 * @param string $delta
 *   The module delta.
 * @param string|null $region
 *   The region where the block is placed.
 *
 * @return array
 *   The block render array.
 */
function _ec_europa_block_get_render_array($module, $delta, $region = NULL) {
  $block = block_load($module, $delta);

  // If not block has been loaded, return empty array.
  if (!isset($block->status)) {
    return array();
  }

  $block_render_array = _block_get_renderable_array(_block_render_blocks(array($block)));

  $block_array = array();
  if (isset($block_render_array[$module . '_' . $delta])) {
    $block_array = $block_render_array[$module . '_' . $delta];
    _atomium_extend_theme_wrappers_property(
      $block_array,
      array(
        is_string($region) ? $region : NULL,
        $block_array['#block']->module,
        $block_array['#block']->delta,
      )
    );
  }

  return $block_array;
}
