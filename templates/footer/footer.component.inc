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
        'footer_bottom' => NULL,
        'footer_improved' => NULL,
      ),
      'template' => 'footer',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_footer() {

  $footer_improved = '<div class="ecl-col-sm ecl-footer__column"><h4 class="ecl-h4"><a class="ecl-link ecl-footer__link" href="#">Digital single market</a></h4></div><div class="ecl-col-sm ecl-footer__column"><p class="ecl-footer__label">Follow us:</p><ul class="ecl-footer__menu ecl-list-inline"><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--facebook ecl-footer__social-icon"></span>Facebook</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span>Twitter</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">Other social media</a></li></ul></div><div class="ecl-col-sm ecl-footer__column"><ul class="ecl-footer__menu ecl-list-inline"><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#">Contact</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#">Site map</a></li></ul></div>';
  $footer_left = '<h4 class="ecl-h4 ecl-footer__title">European Commission</h4><ul class="ecl-footer__menu"><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="https://ec.europa.eu/commission/index_en">Commission and its priorities</a></li><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="https://ec.europa.eu/info/index_en">Policies information and services</a></li></ul>';
  $footer_middle = '<h4 class="ecl-h4 ecl-footer__title">Follow the European Commission</h4><ul class="ecl-footer__menu ecl-list-inline"><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--facebook ecl-footer__social-icon"></span>Facebook</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link" href="#"><span class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span>Twitter</a></li><li class="ecl-footer__menu-item ecl-list-inline__item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">Other social media</a></li></ul>';
  $footer_right = '<h4 class="ecl-h4 ecl-footer__title">European Union</h4><ul class="ecl-footer__menu"><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">EU institutions</a></li><li class="ecl-footer__menu-item"><a class="ecl-link ecl-footer__link ecl-link--external" href="#">European Union</a></li></ul>';
  $footer_bottom = '<ul class="ecl-list-inline ecl-footer__menu"><li class="ecl-list-inline__item ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="http://ec.europa.eu/info/about-commissions-new-web-presence_en">About the Commission\'s new web presence</a></li><li class="ecl-list-inline__item ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="http://ec.europa.eu/info/resources-partners_en">Resources for partners</a></li><li class="ecl-list-inline__item ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="http://ec.europa.eu/info/cookies_en">Cookies</a></li><li class="ecl-list-inline__item ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="http://ec.europa.eu/info/legal-notice_en">Legal notice</a></li><li class="ecl-list-inline__item ecl-footer__menu-item"><a class="ecl-link ecl-footer__link" href="http://ec.europa.eu/info/contact_en">Contact</a></li></ul>';

  return array(
    'label' => 'Footer',
    'description' => 'Footer.',
    'preview' => array(
      'footer_left' => $footer_left,
      'footer_right' => $footer_right,
      'footer_middle' => $footer_middle,
      'footer_bottom' => $footer_bottom,
      'footer_improved' => $footer_improved,
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_footer(&$variables, $hook) {
  $variables['#atomium_recursive'] = TRUE;
}
