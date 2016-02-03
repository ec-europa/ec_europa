/**
 * @file
 * Pager related behaviors.
 */

(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function(context) {
      $('ul.pager').once('pager', function(){
        $('li.select', this).once('pager__item', function(){
          var listItem = this,
              $link = $('a', listItem),
              options = null,
              selected = '',
              value = '',
              title = '';

          if ($link.length > 0) {
            title = Drupal.t('Page') + ' ' + $link.html();
            value = $link.attr('href');
          }
          else {
            title = Drupal.t('Page') + ' ' + $(listItem).html();
            selected = 'selected="selected"';
          }

          if (options != '') {
            options += '<option value="' + value + '"' + selected + '>' + title + '</option>';
            $(listItem).hide();
          }

        });

        if (options != '') {
          $(options).each(function(i) {
            var option = this;
            $(option).data('activation', 'activated');
          });

          var $select = $('<select class="pager__dropdown">' + options + '</select>');


          //    .data('activation', 'activated').on({
          //  keydown: function(event) {
          //    if (event.which === 13) {
          //      if ($(this).data('activation') === 'paused') {
          //        $(this).data('activation', 'activated');
          //        $(this).trigger('change');
          //      }
          //    }
          //    else {
          //      $(this).data('activation', 'paused');
          //    }
          //  },
          //  click: function(event) {
          //    if ($(this).data('activation') === 'paused') {
          //      $(this).data('activation', 'activated');
          //      $(this).trigger('change');
          //    }
          //  },
          //  change: function(event) {
          //    if ($(this).data('activation') === 'activated') {
          //      var optionHref = $(this).val(),
          //        $pagerItem = $('.pager__item:hidden');
          //      $pagerItem.children('a[href="' + optionHref + '"]').click();
          //    }
          //  }
          //});
          $('.pager__combo-container', this).before($select);
          $('.pager__combo-container').hide();
        }
      });
    }
  };
})(jQuery);
