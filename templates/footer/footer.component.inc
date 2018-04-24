<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_footer() {
  return array(
    'footer' => array(
      'variables' => array(
        'footer_left' => NULL,
        'footer_right' => NULL,
        'footer_middle' => NULL,
        'footer_corporate_left' => NULL,
        'footer_corporate_middle' => NULL,
        'footer_corporate_right' => NULL,
        'footer_ec' => NULL,
      ),
      'template' => 'footer',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_footer() {
  $footer_middle = '<p class="ecl-footer__label">Follow us:</p>
          <ul class="ecl-footer__menu ecl-list--inline ecl-footer__social-links">
            <li class="ecl-footer__menu-item">
              <a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--facebook ecl-footer__social-icon"></span>Facebook</a>
            </li>
            <li class="ecl-footer__menu-item">
              <a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span>Twitter</a>
            </li>
            <li class="ecl-footer__menu-item">
              <a class="ecl-link ecl-footer__link ecl-link--external" href="#">Other social media</a>
            </li>
          </ul>';
  $footer_right = '<ul class="ecl-footer__menu ecl-list--unstyled">
            <li class="ecl-footer__menu-item">
              <a class="ecl-link ecl-footer__link" href="#">Contact</a>
            </li>
            <li class="ecl-footer__menu-item">
              <a class="ecl-link ecl-footer__link" href="#">Site map</a>
            </li>
          </ul>';

  return array(
    'label' => 'Footer',
    'description' => 'Footer.',
    'preview' => array(
      'footer_middle' => $footer_middle,
      'footer_right' => $footer_right,
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_footer(array &$variables, $hook) {
  $variables['#atomium_recursive'] = TRUE;

  $variables_block_mapping = array(
    'footer_corporate_left' => array('menu', 'menu-nexteuropa-site-links'),
    'footer_corporate_middle' => array('menu', 'menu-nexteuropa-social-media'),
    'footer_corporate_right' => array('menu', 'menu-nexteuropa-inst-links'),
    'footer_ec' => array('menu', 'menu-nexteuropa-service-links'),
  );

  foreach ($variables_block_mapping as $name => $data) {
    $variables[$name] = _atomium_block_get_render_array($data[0], $data[1]);
  }

  $variables['footer_left'] = array(
    '#theme_wrappers' => array('html_tag'),
    '#tag' => 'h4',
    '#attributes' => array(
      'class' => array(
        'ecl-h4',
      ),
    ),
    'title' => array(
      '#theme' => 'link',
      '#path' => '<front>',
      '#text' => variable_get('site_name', ''),
      '#options' => array(
        'attributes' => array(
          'class' => array(
            'ecl-footer__link',
          ),
        ),
      ),
    ),
  );

  _atomium_extend_theme_wrappers_property(
    $variables['footer_left'],
    array('footer_left', $variables['theme_hook_original']));
  _atomium_extend_theme_property(
    $variables['footer_left']['title'],
    $variables['footer_left']['#theme_wrappers']);
}
