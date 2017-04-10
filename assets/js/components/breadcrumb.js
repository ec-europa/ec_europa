/**
 * @file
 * Breadcrumb related behaviors.
 */

(function ($) {
  Drupal.behaviors.europa_breadcrumb = {
    attach: function (context) {
      $('#breadcrumb').once('breadcrumb', function () {

        // Add collapsible class for js mobile behavior.
        var $breadcrumbWrapper = $('#breadcrumb');
        $breadcrumbWrapper.addClass('breadcrumb--collapsible');

        // Global selectors.
        var $breadcrumbSegmentsWrapper = $breadcrumbWrapper.children('.breadcrumb__segments-wrapper'),
            $breadcrumbSegments = $breadcrumbSegmentsWrapper.children('.breadcrumb__segment'),
            $breadcrumbSegmentFirst = $breadcrumbSegmentsWrapper.children('.breadcrumb__segment--first'),
            $breadcrumbSegmentSecond = $breadcrumbSegmentFirst.next(),
            $last = $breadcrumbSegments.slice(-1);

        // Hiding breadcrumb segments when there is not enough space.
        function toggleBreadcrumbSegments() {
          // Calculating items that are not hidden.
          var $breadcrumbVisibleSegments = $breadcrumbSegments.not('.is-hidden');
          // Calculating sizes.
          var breadcrumbCalculations = {};
          breadcrumbCalculations.wrapperWidth = $breadcrumbWrapper.width();
          breadcrumbCalculations.width = $breadcrumbSegmentsWrapper.width();
          breadcrumbCalculations.itemsWidth = 0;

          $breadcrumbVisibleSegments = $breadcrumbSegments.not('.is-hidden');

          for (var i = 0; i < $breadcrumbSegments.length; i++) {
            breadcrumbCalculations.itemsWidth += $breadcrumbVisibleSegments.eq(i).outerWidth();
          }
          // Local variables.
          var $lastHiddenItem = $breadcrumbSegments.siblings('.is-hidden').last(),
              lastHiddenItemWidth = $lastHiddenItem.width();

          // Hiding segments.
          if (breadcrumbCalculations.wrapperWidth <= breadcrumbCalculations.itemsWidth) {
            if ($breadcrumbSegmentSecond.hasClass('is-hidden')) {
              $lastHiddenItem.next().not('.breadcrumb__segment--last').addClass('is-hidden');
            }
            else {
              $breadcrumbSegmentFirst.addClass('breadcrumb__segment--next-hidden');
              $breadcrumbSegmentSecond.addClass('is-hidden');
            }
          }

          // Showing segments.
          if ((breadcrumbCalculations.itemsWidth + lastHiddenItemWidth) < breadcrumbCalculations.wrapperWidth) {
            if ($lastHiddenItem.hasClass('is-hidden')) {
              $lastHiddenItem.removeClass('is-hidden');
            }
            else {
              $breadcrumbSegmentFirst.removeClass('breadcrumb__segment--next-hidden');
            }
          }

          $breadcrumbVisibleSegments = $breadcrumbSegments.not('.is-hidden');
        }

        // Showing all hidden breadcrumbs.
        function showBreadcrumbs($selector) {
          $selector.hide();
          $breadcrumbWrapper.addClass('is-open');
        }

        // Adding button to breadcrumb element that will be used for showing
        // hidden breadcrumb elements.
        if ($breadcrumbSegments.length > 2) {

          $last.before('<span class="breadcrumb__btn-separator">...</span>');
          var $breadcrumbButton = $breadcrumbWrapper.find('.breadcrumb__btn-separator');
        }

        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register(Drupal.europa.breakpoints.medium, {
            // Desktop.
            match : function () {
              $breadcrumbWrapper.removeClass('is-open');
              $last.css('display', '');

              if ($breadcrumbButton) {
                $breadcrumbButton.hide();
              }

              toggleBreadcrumbSegments();

              $(window).resize(function () {
                toggleBreadcrumbSegments();
              });
            },
            // Mobile.
            unmatch : function () {
              if ($breadcrumbButton) {
                $breadcrumbButton.show();
              }

              $last.css('display', 'block');
              $breadcrumbSegments.removeClass('is-hidden');
              $breadcrumbSegmentFirst.removeClass('breadcrumb__segment--next-hidden');
              $(window).off('resize');
            },

            setup: function () {
              if ($breadcrumbButton) {
                $breadcrumbButton.click(function () {
                  // Adding $(this) as a selector for the showBreadcrumbs function.
                  showBreadcrumbs($(this));
                });
              }
            }
          });
        }
      });
    }
  };
})(jQuery);
