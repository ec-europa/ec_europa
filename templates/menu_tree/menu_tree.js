/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
    Drupal.behaviors.megaMenu = {
        attach: function (context, settings) {
          ECL.megamenu();

        // Fix burger menu.
          $('.ecl-navigation-menu__hamburger').click(function() {
              var button = $(this);
              
              if (button.attr('aria-expanded') == 'true') {
                  button.attr('aria-expanded', 'false');
              } else {
                  button.attr('aria-expanded', 'true');
              }
          });
        }
    };
})(jQuery);
