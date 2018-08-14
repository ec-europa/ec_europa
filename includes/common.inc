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
 * @param array $context
 *   The context array.
 *
 * @return array
 *   The block render array.
 */
function _ec_europa_block_get_render_array($module, $delta, array $context = []) {
  $block = block_load($module, $delta);

  $context += array('suggestions parts' => array());

  // If not block has been loaded, return empty array.
  if (!isset($block->status)) {
    return array();
  }

  $block_render_array = _block_get_renderable_array(
    _block_render_blocks(
      array(
        $block,
      )
    )
  );

  $block_array = array();

  if (!isset($block_render_array[$module . '_' . $delta])) {
    return $block_array;
  }

  $block_array = $block_render_array[$module . '_' . $delta];

  registryonsteroids_alter_recursive_element_children(
    $block_array,
    function (&$element, $element_key, &$recursive_context) {
      _registryonsteroids_alter_add_default_pre_render_variables($element);

      $element['#registryonsteroids']['suggestions']['theme'] = array_merge(
        $recursive_context['suggestions parts'],
        $element['#registryonsteroids']['suggestions']['theme']
      );
    },
    NULL,
    $context
  );

  return $block_array;
}
