/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.ec_table = {
    attach: function (context) {
      ECL.eclTables();
    }
  };
})(jQuery);
