/**
 * @file
<<<<<<< HEAD:lib/themes/europa/js/components/lang-switcher.js
 * Page level language switcher related behaviors.
 */

(function ($) {
  $.fn.selectify = function(options) {
    this.each(function() {

      var attachDropDown = function() {
        var $list  = $(settings.listSelector),
          listClass = $list.attr('class');

        $list.each(function() {
          var $select = $('<select />').addClass(listClass);

          $(this).find('li').each(function() {
            var currentClass = $(this).attr('class');
=======
 * Page level language switcher.
 */
>>>>>>> 14357719795bd856c5313eeb355934e098a06b13:project/themes/europa/js/components/lang-switcher.js

(function ($) {
  'use strict';

  var pageSwitcher = {
    wrapClass: '.lang-select-page',
    listClass: '.lang-select-page__list',
    itemClass: '.lang-select-page__option',
    iconClass: '.lang-select-page__icon',
    unavClass: '.lang-select-page__unavailable',
    wrapWidth: function() {
      return $(pageSwitcher.wrapClass).outerWidth();
    },
    listWidth: function() {
      return $(pageSwitcher.listClass).outerWidth();
    },
    iconWidth: function() {
      return $(pageSwitcher.iconClass).outerWidth();
    },
    unavailableWidth: function() {
      return $(pageSwitcher.unavClass).outerWidth();
    },
    itemsWidth: function() {
      var overallWidth = 0;
      $(pageSwitcher.listClass).children(pageSwitcher.itemClass).each(function() {
        overallWidth += $(this).outerWidth();
      });
      return overallWidth;
    },
    itemsOverflow: function() {
      var availableSpace = pageSwitcher.wrapWidth() - pageSwitcher.iconWidth() - pageSwitcher.unavailableWidth();
      return pageSwitcher.itemsWidth() > availableSpace - 20;
    }
  };

  Drupal.behaviors.languageSwitcherPage = {
    attach: function(context) {
      $('#block-language-selector-page-language-selector-page').once('lang-select-page', function(){
        var pageLanguageSelector = $('.lang-select-page');
        pageLanguageSelector.selectify({
          listSelector: 'lang-select-page__list',
          item: 'lang-select-page__option',
          other: 'lang-select-page__other',
          unavailable: 'lang-select-page__unavailable',
          selected: 'is-selected'
        });

<<<<<<< HEAD:lib/themes/europa/js/components/lang-switcher.js
      if (typeof enquire !== 'undefined') {
        enquire.register(Drupal.europa.breakpoints.small, {
          // Desktop.
          match : function() {
            pageLanguageSelector.trigger('show.list');
            pageLanguageSelector.trigger('hide.dropdown');
          },
          // Mobile.
          unmatch : function() {
            $(window).on('resize', function(){
              if (listIsWider()) {
                pageLanguageSelector.trigger('hide.list');
                pageLanguageSelector.trigger('show.dropdown');
              }
            });
          },
          setup: function() {
            if (listIsWider()) {
=======
        var overflowToggle = function () {
          switch (pageSwitcher.itemsOverflow()) {
            case true:
>>>>>>> 14357719795bd856c5313eeb355934e098a06b13:project/themes/europa/js/components/lang-switcher.js
              pageLanguageSelector.trigger('hide.list');
              pageLanguageSelector.trigger('show.dropdown');
              break;

            case false:
              pageLanguageSelector.trigger('show.list');
              pageLanguageSelector.trigger('hide.dropdown');
              break;
          }
        };

        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register(Drupal.europa.breakpoints.medium, {
            // Desktop case.
            match : function() {
              $(window).resize(function() {
                overflowToggle();
              });
            },
            // Mobile case.
            unmatch : function() {
              $(window).off('resize');
            },
            setup: function() {
              overflowToggle();
            }
          });
        }
      });
    }
  };
})(jQuery);
