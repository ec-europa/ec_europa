(function ($) {
  Drupal.behaviors.atomium_tableselect = {
    attach: function (context, settings) {
      $('th.select-all')
          .find('input:checkbox')
          .addClass('ecl-checkbox__input ecl-u-sr-only')
          .wrap("<label class='ecl-checkbox ecl-form-label'></label>")
          .after("<span class='ecl-checkbox__label'></span>");
    }
  };
}(jQuery));
