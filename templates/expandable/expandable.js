/**

  document.addEventListener('DOMContentLoaded', function () { ECL.initExpandables(); });
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.behaviors.status_messages = {
    attach: function (context) {
      ECL.initExpandables();
    }
  };
})(jQuery);

