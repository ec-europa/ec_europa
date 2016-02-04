/**
 * @file
 * Pager related behaviors.
 */

(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function(context) {
      $('ul.pager').once('pager', function() {
        var options = '',
            pagerContainer = '.pager__combo-container';
        $('li.select', this).once('pager__item', function() {
          var listItem = this,
              $link = $('a', listItem),
              selected = '',
              title = '',
              value = '';

          if ($link.length > 0) {
            title = Drupal.t('Page') + ' ' + $link.html();
            value = $link.attr('href');
          }
          else {
            title = Drupal.t('Page') + ' ' + $(listItem).html();
            selected = 'selected="selected"';
          }
          options += '<option value="' + value + '"' + selected + '>' + title + '</option>';
          $(listItem).hide();
        });
        // If the .once on .pager__items has aggregated markup for the options, make the select.
        if (options != '') {
          var $select = $('<select class="pager__dropdown">' + options + '</select>');
          $select.children().data('activation', 'activated').on({
            keydown: function(event) {
              if (event.which === 13) {
                if ($(this).data('activation') === 'paused') {
                  $(this).data('activation', 'activated');
                  $(this).trigger('change');
                }
              }
              else {
                $(this).data('activation', 'paused');
              }
            },
            click: function(event) {
              if ($(this).data('activation') === 'paused') {
                $(this).data('activation', 'activated');
                $(this).trigger('change');
              }
            },
            change: function(event) {
              if ($(this).data('activation') === 'activated') {
                var optionHref = $(this).val(),
                    $pagerItem = $('.pager__item:hidden');
                $pagerItem.children('a[href="' + optionHref + '"]').click();
              }
            }
          });
          $(pagerContainer, this).before($select);
          $(pagerContainer).hide();
        }
      });
    }
  };
})(jQuery);
