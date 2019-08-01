<?php

/**
 * @file
 * theme-settings.php
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function ec_europa_form_system_theme_settings_alter(&$form, &$form_state) {
  // Build the form.
  if (empty($form['ec_europa'])) {
    $form['ec_europa'] = array(
      '#type' => 'fieldset',
      '#title' => \t('EC Europa settings'),
    );
  }

  $form['ec_europa']['ec_europa_improved_website'] = array(
    '#type' => 'checkbox',
    '#title' => \t('Is this an "improved website"?'),
    '#description' => \t('If this website is an "improved" one, we are going to implement customizations.'),
    '#default_value' => \theme_get_setting('ec_europa_improved_website', 'ec_europa'),
  );

  $form['ec_europa']['ec_europa_improved_website_home'] = array(
    '#type' => 'checkbox',
    '#title' => \t('Do you want to show the site identification also in the home page?'),
    '#description' => \t('The site identification could duplicate your page title in homepage, you can hide it.'),
    '#default_value' => \theme_get_setting('ec_europa_improved_website_home', 'ec_europa'),
    '#states' => array(
      'visible' => array(
        ':input[name="ec_europa_improved_website"]' => array(
          'checked' => TRUE,
        ),
      ),
    ),
  );

  $form['ec_europa']['ec_europa_basic_header'] = array(
    '#type' => 'checkbox',
    '#title' => \t('Use basic header?'),
    '#description' => \t('If this option is selected, the title and introduction sections will be removed from the header.'),
    '#default_value' => \theme_get_setting('ec_europa_basic_header', 'ec_europa'),
  );
}
