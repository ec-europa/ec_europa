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
        }
    };
    Drupal.behaviors.megaMenu = {
        attach: function (context, settings) {
          ECL.megamenu();
        }
    };
})(jQuery);
