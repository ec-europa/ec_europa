<?php
/**
 * @file
 * theme-settings.php
 *
 * Provides theme settings for the Europa theme.
 *
 * @see theme/settings.inc
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function europa_form_system_theme_settings_alter(&$form, &$form_state) {
  // Work-around for a core bug affecting admin themes.
  // @see https://drupal.org/node/943212
  if (isset($form_id)) {
    return;
  }

  // Save the current value for the background image if any.
  $header_background = variable_get('default_header_background', FALSE);
  if ($header_background) {
    $form_state['storage']['default_header_background'] = $header_background;
  }

  // Workaround for bug https://drupal.org/node/1862892.
  $theme_path = drupal_get_path('theme', 'europa');
  $form_state['build_info']['files'][] = $theme_path . '/template.php';
  if (file_exists($theme_path . '/theme-settings.php')) {
    $form_state['build_info']['files'][] = $theme_path . '/theme-settings.php';
  }

  $form['europa'] = array(
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>' . t('Europa settings') . '</small></h2>',
    '#weight' => -11,
  );

  // Header Background.
  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header background'),
    '#group' => 'europa',
  );

  $form['header']['default_header_background'] = array(
    '#type' => 'managed_file',
    '#title' => t('Default image for the header'),
    '#upload_validators' => array(
      'file_validate_is_image' => array(),
      'file_validate_extensions' => array('png jpg jpeg'),
      //'file_validate_image_resolution' => array(2400*900),
    ),
    '#progress_message' => t('Uploading the image'),
    '#progress_indicator' => 'throbber',
    '#default_value' => variable_get('default_header_background', FALSE),
    '#required' => FALSE,
    '#upload_location' => 'public://',
    '#weight' => 0,
    '#theme' => 'theme_image_widget',
    '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif. Minimal image size is 2400x900px'),
  );

  $form['#submit'][] = "europa_theme_settings_submit";
}

/**
 * Submit function for the europa setting form.
 */
function europa_theme_settings_submit(&$form, &$form_state) {
  // User uploaded a new image or there is already a value.
  $fid = $form_state['values']['default_header_background'];
  // We store the previous valuee to be able to delete the css file.
  $prev = isset($form_state['storage']['default_header_background']) ? $form_state['storage']['default_header_background'] : FALSE;

  if ($fid !== 0) {
    if ($fid != $prev) {
      _dt_core_set_default_header_background($fid);
    }
  }
  // There's no default header background, let's check if it has been removed.
  else {
    variable_del('default_header_background');
    if ($prev) {
      $file = new stdClass();
      $file->fid = $prev;
      dt_core_file_delete($file);
    }
  }
}


