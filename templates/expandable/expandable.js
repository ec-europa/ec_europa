/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.ecEuropaExpandable = {
    attach: function (context, settings) {
      ECL.initExpandables();
    }
  };
}(jQuery));
