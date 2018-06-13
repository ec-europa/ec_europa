/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.ecEuropaMenuTree = {
    attach: function (context) {
      if(!Drupal.behaviors.ecEuropaMenuTree.megamenu) {
        ECL.megamenu('.ecl-navigation-menu__root');
        Drupal.behaviors.ecEuropaMenuTree.megamenu = true;
      }
    }
  };
})(jQuery);
