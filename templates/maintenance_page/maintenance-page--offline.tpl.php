<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html>
<html<?php print $atomium['attributes']['html']; ?>>
<head<?php print $atomium['attributes']['head']; ?>>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body<?php print $attributes; ?>>
<div class="ecl-site-switcher ecl-site-switcher--header">
  <ul class="ecl-site-switcher__list ecl-container">
    <li class="ecl-site-switcher__option"><a class="ecl-link ecl-site-switcher__link" href="https://ec.europa.eu/commission/index_en">Commission and its priorities</a></li>
    <li class="ecl-site-switcher__option ecl-site-switcher__option--is-selected"><a class="ecl-link ecl-site-switcher__link" href="https://ec.europa.eu/info/index_en">Policies, information and services</a></li>
  </ul>
</div>
<section class="main-content">
  <header class="ecl-site-header" role="banner">
    <div class="ecl-container ecl-site-header__container">
      <a class="ecl-logo ecl-site-header__logo" href="https://ec.europa.eu/info/index" title="Home - European Commission">
        <span class="ecl-u-sr-only">Home - European Commission</span>
      </a>
      <section class="ecl-site-header__top-bar" aria-label="Site tools">
        <div class="ecl-lang-select-sites">
          <a href="#" class="ecl-lang-select-sites__link">
            <span class="ecl-lang-select-sites__label">English</span>
            <span class="ecl-lang-select-sites__code">
              <span class="ecl-icon ecl-icon--language ecl-lang-select-sites__icon"></span>
              <span class="ecl-lang-select-sites__code-text">en</span>
            </span>
          </a>
        </div>
        <form accept-charset="UTF-8" action="http://ec.europa.eu/geninfo/query/resultaction.jsp" class="ecl-search-form search-form" id="nexteuropa-europa-search-search-form" method="get">
          <label class="ecl-search-form__textfield-wrapper">
            <span class="ecl-u-sr-only">Search this website</span>
            <input class="ecl-search-form__textfield ecl-text-input form-text" id="edit-querytext" maxlength="128" name="QueryText" placeholder="Search this website" size="30" type="text"/></label>
          <button class="btn-search ecl-button ecl-button--form ecl-search-form__button form-submit" id="edit-europa-search-submit" name="op" tabindex="-1" type="submit" value="Search">Search</button>
          <input name="swlang" type="hidden" value="en"/>
          <input name="form_id" type="hidden" value="nexteuropa_europa_search_search_form"/>
        </form>
      </section>
    </div>
  </header>
  <div class="ecl-page-header">
    <nav class="ecl-breadcrumbs ecl-container" aria-label="breadcrumbs">
      <span class="ecl-u-sr-only">You are here:</span>
      <ol class="ecl-breadcrumbs__segments-wrapper">
        <li class="ecl-breadcrumbs__segment ecl-breadcrumbs__segment--first">
          <a href="http://ec.europa.eu/" class="ecl-breadcrumbs__link">European Commission</a>
        </li>
      </ol>
    </nav>
    <div class="ecl-page-header__body ecl-container">
      <div class="ecl-page-header__title">
        <h1 class=" ecl-heading ecl-heading--h1 ecl-u-color-white">Site offline</h1>
      </div>
    </div>
  </div>
  <div class="page-content">
    <div class="ecl-container">
      <a id="main-content" tabindex="-1"></a>
      <div class="row">
        <section class="section <?php print $content_column_class; ?>">
          <h2>This website is currently under maintenance</h2>
          <hr/>
          <p>We should be back shortly. Thank you for your patience.</p>
          <p><br><br><br><br><br><br><br><br><br></p>
        </section>
      </div>
    </div>
  </div>
</section>
<footer class="ecl-footer">
  <div class="ecl-footer__site-corporate">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm ecl-footer__column">
          <aside class="hook__region__footer_left region-footer-left" role="complementary">  <h4 class="block__title ecl-footer__title ecl-h4 title">European Commission</h4>
            <div class="block-content">
              <ul class="ecl-footer__menu menu_tree-level-1">
                <li class="ecl-footer__menu-item first leaf">
                  <a class="ecl-footer__link ecl-link" href="https://ec.europa.eu/commission/index">Commission and its priorities</a>
                </li>
                <li class="ecl-footer__menu-item last leaf">
                  <a class="ecl-footer__link ecl-link" href="https://ec.europa.eu/info/index">Policies, information and services</a>
                </li>
              </ul>
            </div>
          </aside>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <aside class="hook__region__footer_middle region-footer-middle" role="complementary">
            <h4 class="block__title ecl-footer__title ecl-h4 title">Follow the European Commission</h4>
            <div class="block-content">
              <ul class="ecl-footer__menu ecl-list-inline menu_tree-level-1">
                <li class="ecl-footer__menu-item ecl-list-inline__item first leaf">
                  <a class="ecl-footer__link ecl-link" href="https://www.facebook.com/EuropeanCommission"><span class="ecl-footer__social-icon ecl-icon ecl-icon--facebook"></span>Facebook</a>
                </li>
                <li class="ecl-footer__menu-item ecl-list-inline__item leaf">
                  <a class="ecl-footer__link ecl-link" href="https://twitter.com/eu_commission"><span class="ecl-footer__social-icon ecl-icon ecl-icon--twitter"></span> Twitter</a>
                </li>
                <li class="ecl-footer__menu-item ecl-list-inline__item last leaf">
                  <a class="ecl-footer__link ecl-link" href="http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm">Other social media</a>
                </li>
              </ul>
            </div>
          </aside>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <aside class="hook__region__footer_right region-footer-right" role="complementary">  <h4 class="block__title ecl-footer__title ecl-h4 title">European Union</h4>
            <div class="block-content">
              <ul class="ecl-footer__menu menu_tree-level-1">
                <li class="ecl-footer__menu-item first leaf">
                  <a class="ecl-footer__link ecl-link ecl-link--external" href="https://europa.eu/european-union/about-eu/institutions-bodies">EU institutions</a>
                </li>
                <li class="ecl-footer__menu-item last leaf">
                  <a class="ecl-footer__link ecl-link ecl-link--external" href="https://europa.eu/european-union/index">European Union</a>
                </li>
              </ul>
            </div>
          </aside>
        </div>
      </div>
    </div>
  </div>
  <div class="ecl-footer__ec">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm">
          <aside class="hook__region__footer_bottom region-footer-bottom" role="complementary">
            <div class="block-content">
              <ul class="ecl-footer__menu ecl-list-inline menu_tree-level-1">
                <li class="ecl-footer__menu-item ecl-list-inline__item first leaf">
                  <a class="ecl-footer__link ecl-link" href="https://ec.europa.eu/info/about-commissions-new-web-presence">About the Commission's new web presence</a>
                </li>
                <li class="ecl-footer__menu-item ecl-list-inline__item leaf">
                  <a class="ecl-footer__link ecl-link" href="http://ec.europa.eu/info/resources-partners">Resources for partners</a>
                </li>
                <li class="ecl-footer__menu-item ecl-list-inline__item leaf">
                  <a class="ecl-footer__link ecl-link" href="https://ec.europa.eu/info/cookies">Cookies</a>
                </li>
                <li class="ecl-footer__menu-item ecl-list-inline__item leaf"><a class="ecl-footer__link ecl-link" href="https://ec.europa.eu/info/legal-notice">Legal notice</a>
                </li>
                <li class="ecl-footer__menu-item ecl-list-inline__item last leaf"><a class="ecl-footer__link ecl-link" href="https://ec.europa.eu/info/contact">Contact</a>
                </li>
              </ul>
            </div>
          </aside>
        </div>
      </div>
    </div>
  </div>
</footer>
</body>
