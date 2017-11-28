/**
 * @file
 * JS file for Europa theme.
 */

(function ($) {
    /**
     * Theme function for a vertical tab.
     *
     * @param settings
     *   An object with the following keys:
     *   - title: The name of the tab.
     * @return
     *   This function has to return an object with at least these keys:
     *   - item: The root tab jQuery element
     *   - link: The anchor tag that acts as the clickable area of the tab
     *       (jQuery version)
     *   - summary: The jQuery element that contains the tab summary
     */
    Drupal.theme.verticalTab = function (settings) {
        var tab = {};
        tab.item = $('<li class="vertical-tab-button" tabindex="-1"></li>')
            .append(tab.link = $('<a class="ecl-link" href="#"></a>')
                .append(tab.title = $('<strong></strong>').text(settings.title))
                .append(tab.summary = $('<span class="summary"></span>')
                )
            );
        return tab;
    };
})(jQuery);

