/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.ec_status_messages = {
    attach: function (context) {
      ECL.initMessages();
    }
  };
})(jQuery);
