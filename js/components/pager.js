/**
 * @file
 * Pager related behaviors.
 */

(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function(context) {
      $('ul.pager').once('pager', function(){
        var options = null;
        $('li.select', this).once('pager__item', function(){
          var listItem = this,
              $link = $('a', listItem),
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
          options += '<option value="' + value + '"' + selected + '>' + title + '</option>';
          $(listItem).hide();
        });
        if (options != ''){
          var $select = $('<select class="pager__dropdown">' + options + '</select>');
          $select.on({
            change: function(){
              var target = String($(this).val());
              window.location.href = $("a[href='" + target + "']").first().attr('href');
            }
          });
          $('.pager__combo-container', this).before($select);
          $('.pager__combo-container').hide();
        }
      });
    }
  };
})(jQuery);
