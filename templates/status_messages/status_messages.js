/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.ecEuropaStatusMessages = {
    attach: function (context) {
      ECL.initMessages();
    }
  };
})(jQuery);
