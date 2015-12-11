/**
 * @file
 * File component related behaviors.
 */

(function ($) {
  Drupal.behaviors.dt_file = {
    attach: function(context) {
      "use strict";
      var $button = $('.file__translations-control'),
          $translations = $('.file__translations-table');

      $button.click(function() {
        var self = this;
        $translations.collapse('toggle');
        $(self).toggleClass('is-collapsed');
      });
    }
  };
})(jQuery);
