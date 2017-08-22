/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.expandable = {
    attach: function (context, settings) {
      ECL.initExpandables();
    }
  };
}(jQuery));
