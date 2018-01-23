/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
    Drupal.behaviors.ecEuropaLangSelectSite = {
        attach: function (context) {
            ECL.dialogs({
                dialogOverlayId: 'ecl-overlay-language-list',
                triggerElementsSelector: '#ecl-lang-select-sites__overlay'
            });
        }
    };
})(jQuery);


