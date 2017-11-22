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
  $footer_left = '<h4 class="ecl-h4 ecl-footer__title">European Commission</h4><ul class="ecl-footer__menu"><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="https://ec.europa.eu/commission/index_en">Commission and its priorities</a></li><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="https://ec.europa.eu/info/index_en">Policies information and services</a></li></ul>';
  $footer_middle = '<h4 class="ecl-h4 ecl-footer__title">Follow the European Commission</h4><ul class="ecl-footer__menu ecl-list-inline"><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--facebook ecl-footer__social-icon"></span>Facebook</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span>Twitter</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">Other social media</a></li></ul>';
  $footer_right = '<h4 class="ecl-h4 ecl-footer__title">European Union</h4><ul class="ecl-footer__menu"><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">EU institutions</a></li><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">European Union</a></li></ul>';

  return array(
    'label' => 'Footer',
    'description' => 'Footer.',
    'preview' => array(
      'footer_left' => $footer_left,
      'footer_right' => $footer_right,
      'footer_middle' => $footer_middle,
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_footer(&$variables, $hook) {
  $variables['#atomium_recursive'] = TRUE;

  $variables_block_mapping = array(
    'footer_corporate_left' => array('menu', 'menu-nexteuropa-site-links'),
    'footer_corporate_middle' => array('menu', 'menu-nexteuropa-social-media'),
    'footer_corporate_right' => array('menu', 'menu-nexteuropa-inst-links'),
    'footer_ec' => array('menu', 'menu-nexteuropa-service-links'),
  );

  foreach ($variables_block_mapping as $name => $data) {
    $variables[$name] = _block_get_renderable_array(
      _block_render_blocks(
        array(
          block_load($data[0], $data[1]),
        )
      )
    );
  }
}
