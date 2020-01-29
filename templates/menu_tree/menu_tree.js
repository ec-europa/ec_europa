/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
    Drupal.behaviors.ecEuropaMenuTree = {
        attach: function (context) {
            $('.ecl-navigation-menu__root').once('ecEuropaMenuTree', function() {
                ECL.megamenu('.ecl-navigation-menu__root');
            });
            if ($('.ecl-navigation-menu__group').length) {
              $('.ecl-navigation-menu__group').once('ecEuropaSubmenuTree', function() {
                  ECL.megamenu('.ecl-navigation-menu__group');
              });
            }
        }
    };
    Drupal.behaviors.megaMenu = {
        attach: function (context, settings) {
          ECL.megamenu();
        }
    };
})(jQuery);
