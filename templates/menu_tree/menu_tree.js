/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.ecEuropaMenuTree = {
    attach: function (context) {
      if (jQuery(context).find('.ecl-navigation-menu__root').once('ecEuropaMenuTree').length > 0) {
        ECL.megamenu('.ecl-navigation-menu__root');
      };
    }
  };
})(jQuery);
