<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_tag() {
   return array(
    'tag' => array(
      '#theme' => 'link',
      '#text' => NULL,
      '#path' => NULL,
      '#options' => array(
        'attributes' => array(
          'class' => array(
            'ecl-tag__item',
          ),
        ),
      ),
    ),
  );
}