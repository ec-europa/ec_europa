<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_banner() {
  return array(
    'label' => 'Banner Hero',
    'description' => '<p>The banner is used for optional, mainly promotional material. The content presented varies with the purpose of the site: it can be relevant news about the site or specific site-links.</p><p>Is a large web banner image, prominently placed on a web page, generally at the top.</p>',
    'dependencies' => array('nexteuropa_formatters_views'),
    'preview' => array(
      'image' => 'https://v1--europa-component-library.netlify.com/ec/assets/demo_images/nature-demo-1.jpg',
      'link' => '#',
      'title' => 'White Paper on the future of Europe',
      'description' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation.',
    ),
  );
}
