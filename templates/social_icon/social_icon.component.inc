<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_social_icon() {
  return array(
    'label' => 'Social Icon',
    'description' => 'Social Icon.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_social_icon($form, &$form_state) {
  $type = array(
    'Arto', 'Facebook', 'Bebo', 'Bitly', 'Blinklist', 'Blog', 'Blogger', 'Delicious', 'Digg', 'Diigo',
    'Dzone', 'Email', 'Flickr', 'Foursquare', 'Generic', 'Google', 'Gplus', 'Instagram', 'Linkarena', 'Linkedin',
    'Live', 'Meneame', 'Misterwong', 'Myspace', 'Netlog', 'Netvibes', 'Newsvine', 'Nujij', 'Pinterest', 'Pocket',
    'Reddit', 'RSS', 'Share', 'Skype', 'Slashdot', 'Sonico', 'Spotify', 'Storify', 'Studivz', 'Stumbleupon',
    'Technorati', 'Tuenti', 'Tumblr', 'Tumblr', 'Twitter', 'Viadeo', 'Vine', 'Wordpress', 'Wykop', 'Xerpi',
    'Yammer', 'Youtube', 'Print',
  );

  foreach ($type as $item) {
    $form['element'][] = array(
      '#theme' => 'social_icon',
      '#title' => 'Social Icon for ' . $item,
      '#type' => strtolower($item),
      '#text' => $item,
      '#theme_wrappers' => array('form_element'),
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_social_icon(&$variables, $hook) {
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'][] = 'ecl-icon-social';
  $variables['attributes_array']['class'][] = 'ecl-icon-social--' . $variables['type'];
}
