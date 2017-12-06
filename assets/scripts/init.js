
(function ($) {
  Drupal.behaviors.ecEuropaExpandable = {
    attach: function (context, settings) {
      // This must only be instantiated once.
      // This will be probably removed once INNO team found out a workaround.
      ECL.initExpandables('.ecl-navigation-menu__toggle');
    }
  };
}(jQuery));
