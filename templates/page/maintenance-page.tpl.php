<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 *
 * Site identity:
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * In a multisite set up, these variables should be set for the
 * tpl to be used/
 * $conf['install_profile'] = 'multisite_drupal_XXX';
 * $conf['maintenance_theme'] = 'ec_europa';
 *
 * @ingroup themeable
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 */
?>
<!DOCTYPE html>
<!--[if IE 8 ]>
<html class="no-js ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" prefix="<?php print $rdf_namespaces;?>">
<![endif]-->
<!--[if (gt IE 8)|!(IE)]><!-->
<html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" prefix="<?php print $rdf_namespaces;?>">
<!--<![endif]-->
<head profile="<?php print $grddl_profile; ?>">
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lte IE 9]>
  <script src="<?php print $theme_path . '/js/libraries/matchMedia/matchMedia.js'; ?>"></script>
  <script src="<?php print $theme_path . '/js/libraries/matchMedia/matchMedia.addListener.js'; ?>"></script>
  <![endif]-->
  <!--[if lt IE 9]>
  <script src="<?php print $theme_path . '/js/libraries/html5shiv.min.js'; ?>"></script>
  <script src="<?php print $theme_path . '/js/libraries/respond.min.js'; ?>"></script>
  <![endif]-->
  <?php print $scripts; ?>
</head>
<body<?php print $attributes;?>>
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
        <?php if ($title): ?>
        <h1 class=" ecl-heading ecl-heading--h1 ecl-u-color-white"><?php print filter_xss($title); ?></h1>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <div class="page-content">
    <div class="ecl-container">
      <a id="main-content" tabindex="-1"></a>
      <div class="row">
        <section class="section <?php print $content_column_class; ?>">
          <p><?php print $content; ?></p>
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
