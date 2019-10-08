<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_timelines() {
  return array(
    'label' => 'Timelines',
    'description' => 'Timelines.',
    'dependencies' => array('nexteuropa_formatters_views'),
    'preview' => array(
      'title' => 'By late 2015',
      'text' => 'The Commission will convene the first energy infrastructure forum to discuss and find solutions to issues that are common to all regions across Europe.',
      'footer' => array(
        '#theme' => _atomium_extend_theme_hook('button__call'),
        '#button_type' => 'button',
        '#value' => 'Show all timeline',
        '#attributes' => array(
          'class' => array(
            'ecl-button--caret-down',
          ),
        ),
      ),
    ),
  );
}
