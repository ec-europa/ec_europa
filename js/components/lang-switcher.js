/**
 * @file
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

            switch (currentClass) {
              case 'lang-select-page__option is-selected':
                var $option = $('<option />');
                $option.html($(this).html()).attr('selected', true);;
                $select.append($option);
                break;

              case 'lang-select-page__option lang-select-page__other':
                var $option = $('<option />');
                $option.attr('value', $(this).find('a').attr('href')).html($(this).html());
                $select.append($option);
                break;
            }
          });

          if (!$list.parent().find('select').length) {
            $list.parent().append($select);
            settings.listWrapper.find('select').hide();
            $select.on({
              change: function(event) {
                var optionHref = $(this).val(),
                  $item = $list.find('li'),
                  $location = $item.children('a[href="' + optionHref + '"]');

                window.location.href = $location.attr('href');
              }
            });
          }
        });
      };
      var hideDropDown = function() {
        settings.listWrapper.find('select').hide();
      };
      var hideList = function() {
        settings.listWrapper
          .find(settings.listSelector)
          .find(settings.other)
          .hide();
        settings.listWrapper
          .find(settings.listSelector)
          .find(settings.selected)
          .hide();
      };
      var showDropDown = function() {
        settings.listWrapper.find('select').show();
      };
      var showList = function() {
        $(settings.listWrapper)
          .find(settings.listSelector)
          .find(settings.other)
          .show();
        $(settings.listWrapper)
          .find(settings.listSelector)
          .find(settings.selected)
          .show();
      };
      var settings = $.extend({
        listWrapper: $(this),
        listSelector: 'ul',
        item: 'li',
        other: '.item__other',
        selected: '.item--selected'
      }, options);

      settings.listWrapper.on('hide.dropdown', hideDropDown);
      settings.listWrapper.on('hide.list', hideList);
      settings.listWrapper.on('show.dropdown', showDropDown);
      settings.listWrapper.on('show.list', showList);
      attachDropDown();
    });
  };

  /**
   * Returns true if list is bigger than wrapper.
   */
  function listIsWider(){
    var $wrapper = $('.lang-select-page'),
      $list = $('.lang-select-page__list'),
      $icon = $('.lang-select-page__icon');

    if ($list.length && $list.is(':visible') && $wrapper.length) {
      // 40px of buffer in wrapper which is compensated due to font icon changing size.
      return ($list.outerWidth() + $icon.outerWidth() > $wrapper.outerWidth() - 40);
    }
  }

  Drupal.behaviors.languageSwitcherPage = {
    attach: function(context) {
      var pageLanguageSelector = $('.lang-select-page');
      pageLanguageSelector.selectify({
        listSelector: 'ul.lang-select-page__list',
        item: 'lang-select-page__option',
        other: '.lang-select-page__other',
        selected: '.is-selected'
      });

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
              pageLanguageSelector.trigger('hide.list');
              pageLanguageSelector.trigger('show.dropdown');
            }
          }
        }, true);
      }
    }
  };
})(jQuery);
