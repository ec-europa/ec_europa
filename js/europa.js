/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
  Drupal.europa = Drupal.europa || {};
  Drupal.europa.breakpoints = Drupal.europa.breakpoints || {};

  // TODO:
  // Populate the breakpoints with those comming from Breakpoints module.
  // @see breakpoints js module for potential solution.
  Drupal.europa.breakpoints.medium = 'screen and (min-width: 480px)';
  Drupal.europa.breakpoints.small = 'screen and (min-width: 768px)';

  Drupal.behaviors.timeline = {
    attach: function(context) {
      var $timelineSelector = $('.timeline');
      $($timelineSelector).once('timeline', function(){
        var timelineItemSelector = '.timeline .timeline__item',
            timelineItemsCount = $(timelineItemSelector).length,
            timeLineButton = '<button class="btn btn-time-line">' + Drupal.t("Show all timeline") + '</button>';

        if (timelineItemsCount > 4) {
          $timelineSelector.append(timeLineButton);
          $(timelineItemSelector).each(function(i){
            if (i > 4) {
              $(this).addClass('hidden');
            }
          });

          $('.btn-time-line', this).click(function(e) {
            e.preventDefault();
            $(this).hide();
            $(timelineItemSelector).removeClass('hidden');
            // Refreshing scrollspy to recalculate the offset.
            $('body').scrollspy('refresh');
          });
        }
      });
    }
  };

  Drupal.behaviors.equal_blocks = {
    attach: function (context) {
      $('.equal-height').once('equal-height-blocks', function() {
        $equal_height_block = $(this);
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register(Drupal.europa.breakpoints.small, {
            // Desktop.
            match : function() {
              Drupal.behaviors.equal_blocks.fixBlockHeights($equal_height_block, false);
            },
            // Mobile.
            unmatch : function() {
              Drupal.behaviors.equal_blocks.fixBlockHeights($equal_height_block, true);
            }
          });
        }
      });
    },

    fixBlockHeights: function ($block, stop) {
      $block.each(function () {
        $wrapper = $(this);
        var $blocks = [];

        // Columns and rows.
        if ($wrapper.hasClass('listing__wrapper--two-columns') || $wrapper.hasClass('listing__wrapper--row-two')) {
          var selector = '.listing__item-link > :first-child';
          // Two column listing blocks.
          if ($wrapper.hasClass('listing__wrapper--two-columns')) {
            $first_column = $wrapper.find('.listing:first-child .listing__item');
            $last_column = $wrapper.find('.listing:last-child .listing__item');
          }
          // Row with two items.
          else if ($wrapper.hasClass('listing__wrapper--row-two')) {
            $first_column = $wrapper.find('.listing .listing__item:nth-child(odd)');
            $last_column = $wrapper.find('.listing .listing__item:nth-child(even)');
          }

          // First column always contains more items if not equal.
          $first_column.each(function(index, item) {
            // Only applicable if there's an item in the other column at index.
            if (!$last_column.eq(index)) {
              return;
            }
            var $row = $(item).find(selector).add($last_column.eq(index).find(selector));
            $blocks.push($row);
          });
        }
        // Simple listing blocks.
        else {
          $blocks.push($wrapper.find('.listing__item-link > :first-child'));
        }

        var i, max;
        for (i = 0, max = $blocks.length; i < max; i++) {
          var $block = $blocks[i].equalHeight();
        }
      });
    }
  };

  Drupal.behaviors.europa_collapse = {
    attach: function (context) {
      Drupal.europa.collapsing();
    }
  };

  Drupal.europa.collapsing = function(showText, hideText) {
    if (!showText) {
      showText = Drupal.t("Show");
    }

    if (!hideText) {
      hideText = Drupal.t("Hide");
    }

    $('button[data-toggle=collapse]').each(function() {
      var dependentId = $(this).attr('data-target');
      var toggler = $(dependentId).hasClass('in') ? hideText : showText;
      var arrow = $('.icon', $(this));
      var fillMe = $('.toggling-text', $(this));
      fillMe.text(toggler);

      $(this).click(function() {
        var up = 'icon--up';
        var down = 'icon--down';
        var add = arrow.hasClass(down) ? up : down;
        var rem = arrow.hasClass(down) ? down : up;
        toggler = fillMe.text() == hideText ? showText : hideText;
        fillMe.text(toggler);
        arrow.addClass(add).removeClass(rem);
      });
    });
  };

  var trackElements = [];
  var errorEventSent = 'Piwik, trackEvent was not fired up.';
  /**
   * Acts like a wrapper for Piwik push method.
   *
   * For Piwik parameters refer to {@see https://developer.piwik.org/guides/tracking-javascript-guide}
   *
   * @param int {triggerValue}
   *   How many times should the call be triggered by page load
   *   Accepts 0,1 (0 for always and 1 just for one time).
   * @param str {action}
   *   Defines Action in piwik.
   * @param str {category}
   *   Defines category in piwik.
   * @param {value}
   *  Defines category in piwik.
   * @param {data}
   *  Defines category in piwik.
   */
  PiwikDTT = {
    sendTrack: function(triggerValue, action, category, value, data) {
      if (typeof action === "undefined" || action === null || action === '') {
        action = "trackEvent";
      }
      // Trigger only once.
      if (triggerValue == 1) {
        var innerElements = (triggerValue + action + category + value + data);
        if ($.inArray(innerElements, trackElements) === -1) {
          trackElements.push(innerElements);
          if (typeof _paq != 'undefined') {
            _paq.push([action, category, value, data]);
          }
        }
      }
      // Always trigger.
      if (triggerValue === 0) {
        if (typeof _paq != 'undefined') {
          _paq.push([action, category, value, data]);
        }
      }
    }
  };
})(jQuery);
