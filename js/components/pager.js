/**
 * @file
 * Pager related behaviors.
 */

(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function(context) {
      $('ul.pager').once('pager', function() {
        var options = '',
            pagerContainer = '.pager__combo-container',
            pagerItemClass = '.pager__item';
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
          // Listen for a change in the select, take the option value and emulate a click on the original element.
          $select.on('change', function(e) {
            var valueSelected = this.value;
            // Emulate the selection.
            $(pagerItemClass).find('a[href="' + valueSelected + '"]').click();
          });
          $(pagerContainer, this).before($select);
          $(pagerContainer).hide();
        }
      });
    }
  };
})(jQuery);
