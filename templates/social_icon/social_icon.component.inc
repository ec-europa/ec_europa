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
    'dependencies' => array('nexteuropa_formatters_fields'),
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_social_icon(array $form, array &$form_state) {
  $type = array(
    'Arto', 'Facebook', 'Bebo', 'Bitly', 'Blinklist', 'Blog', 'Blogger', 'Delicious', 'Digg', 'Diigo',
    'Dzone', 'Email', 'Flickr', 'Foursquare', 'Generic', 'Google', 'Gplus', 'Instagram', 'Linkarena', 'Linkedin',
    'Live', 'Meneame', 'Misterwong', 'Myspace', 'Netlog', 'Netvibes', 'Newsvine', 'Nujij', 'Pinterest', 'Pocket',
    'Reddit', 'RSS', 'Share', 'Skype', 'Slashdot', 'Sonico', 'Spotify', 'Storify', 'Studivz', 'Stumbleupon',
    'Technorati', 'Tuenti', 'Tumblr', 'Tumblr', 'Twitter', 'Viadeo', 'Vine', 'Wordpress', 'Wykop', 'Xerpi',
    'Yammer', 'Youtube', 'Print',
  );

  foreach ($type as $item) {
    $variant = \mb_strtolower($item);
    $form['element'][] = array(
      '#theme' => \_atomium_extend_theme_hook('social_icon', $variant),
      '#title' => 'Social icon for ' . $item,
      '#type' => $variant,
      '#text' => $item,
      '#theme_wrappers' => array('form_element'),
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_social_icon(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array(
    'ecl-icon-social',
    'ecl-icon-social--' . $variables['type'],
  ));
}
