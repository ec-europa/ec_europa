<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_footer(array $existing, $type, $theme, $path) {
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
  $footer_middle = '<h2 class="ecl-heading ecl-heading--h4 ecl-footer__column-title" id="footer-corporate-social-media">Follow the European Commission</h2>
        <ul class="ecl-list ecl-list--unstyled ecl-list--inline ecl-footer__list ecl-footer__list--inline  ecl-footer__social-links" aria-labelledby="footer-corporate-social-media">
                      <li class="ecl-footer__list-item">
                              






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="../../example.html#">                    <span class="ecl-icon ecl-icon--facebook ecl-footer__social-icon"></span><span>Facebook</span>                  </a>
                          </li>
                      <li class="ecl-footer__list-item">
                              






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="../../example.html#">                    <span class="ecl-icon ecl-icon--twitter ecl-footer__social-icon"></span><span>Twitter</span>                  </a>
                          </li>
                      <li class="ecl-footer__list-item">
                              






                            
  



<a class="ecl-link ecl-link--inverted ecl-link--external ecl-footer__link" href="../../example.html#">Other social media</a>
                          </li>
                  </ul>';
  $footer_right = '<h2 class="ecl-heading ecl-heading--h4 ecl-footer__column-title" id="footer-corporate-about-eu">European Union</h2>
        <ul class="ecl-list ecl-list--unstyled ecl-footer__list" aria-labelledby="footer-corporate-about-eu">
                      <li class="ecl-footer__list-item">
              






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="../../example.html#">EU institutions</a>
            </li>
                      <li class="ecl-footer__list-item">
              






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="../../example.html#">European Union</a>
            </li>
                  </ul>';

  $footer_left = '
  <h2 class="ecl-heading ecl-heading--h4 ecl-footer__column-title" id="footer-corporate-about-ec">European Commission</h2>
  <ul class="ecl-list ecl-list--unstyled ecl-footer__list" aria-labelledby="footer-corporate-about-ec">
                      <li class="ecl-footer__list-item">
              






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="https://ec.europa.eu/commission/index_en">Commission and its priorities</a>
            </li>
                      <li class="ecl-footer__list-item">
              






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="https://ec.europa.eu/info/index_en">Policies, information and services</a>
            </li>
                  </ul>
  ';

  $footer_ec = '<ul class="ecl-list ecl-list--unstyled ecl-list--inline ecl-footer__list ecl-footer__list--inline">
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="http://ec.europa.eu/info/about-commissions-new-web-presence_en">About the Commission\'s new web presence</a>
          </li>
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="https://ec.europa.eu/info/language-policy_en">Language policy</a>
          </li>
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="http://ec.europa.eu/info/resources-partners_en">Resources for partners</a>
          </li>
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="http://ec.europa.eu/info/cookies_en">Cookies</a>
          </li>
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="https://ec.europa.eu/info/privacy-policy_en">Privacy policy</a>
          </li>
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="http://ec.europa.eu/info/legal-notice_en">Legal notice</a>
          </li>
                    <li class="ecl-footer__list-item">
            






        
  



<a class="ecl-link ecl-link--inverted ecl-footer__link" href="http://ec.europa.eu/info/contact_en">Contact</a>
          </li>
                  </ul>';

  return array(
    'label' => 'Footer',
    'description' => 'Footer.',
    'preview' => array(
      'footer_left' => $footer_left,
      'footer_middle' => $footer_middle,
      'footer_right' => $footer_right,
      'footer_ec' => $footer_ec,
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
    if (empty($variables[$name])) {
      $variables[$name] = _atomium_block_get_render_array($data[0], $data[1]);
    }
  }

  if (empty($variables['footer_left'])) {
    $variables['footer_left'] = array(
      '#theme' => _atomium_extend_theme_hook('html_tag'),
      '#tag' => 'h4',
      '#attributes' => array(
        'class' => array(
          'ecl-h4',
        ),
      ),
      array(
        '#theme' => _atomium_extend_theme_hook('link', array('footer_left', $variables['theme_hook_original'])),
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
  }
}
