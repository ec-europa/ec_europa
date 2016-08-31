/**
 * @file
 * Pager related behaviors.
 */

(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function (context) {
      $('ul.pager').once('pager', function () {
        var options = '',
            pagerContainer = '.pager__combo-container',
            pagerItemClass = '.pager__item';
        $('li.select', this).once('pager__item', function () {
          var listItem = this,
              $link = $('a', listItem),
              title = Drupal.t('Page'),
              pageNum = '',
              selected = '',
              value = '';

          if ($link.length > 0) {
            pageNum = $link.text();
            value = $link.attr('href');
          }
          else {
            pageNum = $(listItem).text();
            selected = 'selected';
          }
          option = ('<option value="' + value + '" ' + selected + '>' + title + ' ' + pageNum + '</option>').trim();
          options += option;
          $(listItem).hide();
        });
        // If the .once on .pager__items has aggregated markup for the options, make the select.
        if (options != '') {
          var $select = $('<select class="pager__dropdown">' + options + '</select>');
          // Listen for a change in the select, take the option value and emulate a click on the original element.
          $select.on('change', function (e) {
            var link = document.querySelector('a[href="' + this.value + '"]');
            // Emulate the selection.
            if (link) {
              link.click();
            }
          });
          $(pagerContainer, this).before($select);
          $select.after($('<span class="pager__separator"></span>'));
          $(pagerContainer).hide();
        }
      });
    }
  };
})(jQuery);
