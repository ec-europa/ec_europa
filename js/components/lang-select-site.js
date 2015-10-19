(function ($) {
    Drupal.behaviors.europa_pager = {
      attach: function(context) {
        var $overlay = $('.splash-page--overlay'),
            overlay = '.splash-page--overlay',
            closeBtn = '.splash-page__btn-close',
            body = 'body';

        $('.lang-select-site').on('click', 'a.lang-select-site__link', function(event){

          // We only want to load it once.
          if (!$overlay.find(closeBtn).length) {

            $.get($(this).attr('href'), function(splashscreen) {
              // Store our object.
              var $jQueryObject = $($.parseHTML(splashscreen));
              // Output the part we want to our overlay.
              $overlay.html($jQueryObject.find('.page-content'))
            });
          }

          // Show overlay.
          $(overlay).show();
          $(body).addClass('disablescroll');

          // Hide frame on click.
          $overlay.on('click', closeBtn, function(event){
            $(overlay).hide();
            $(body).removeClass('disablescroll');
            // Prevent the actual close a href to trigger. This should only work
            // if javascript is disabled.
            event.preventDefault();
          });

          // Prevent the default click, if javascript is disabled this link
          // will keep on working.
          event.preventDefault();
        });
      }
    };
})(jQuery);
