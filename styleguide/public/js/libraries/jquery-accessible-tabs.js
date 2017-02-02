/**
 * @file
 * Accessible tab panel system, with jQuery using ARIA - bootstrap active class ready.
 *
 * Website: https://github.com/ec-europa/jquery-accessible-tabs-aria
 * License MIT: https://github.com/ec-europa/jquery-accessible-tabs-aria/blob/master/LICENSE
 */

jQuery(document).ready(function ($) {
    // Store current URL hash.
    var hash = window.location.hash.replace("#", "");

    // Get tabs
    var $tabs = $(".js-tabs");
    if ($tabs.length) {

        var $tab_list = $tabs.find(".js-tablist");
        $tab_list.each(function () {
            var $this_tab_list = $(this),
                options = $this_tab_list.data(),
                $tabs_prefix_classes = typeof options.tabsPrefixClass !== 'undefined' ? options.tabsPrefixClass + '-' : '',
                $hx = typeof options.hx !== 'undefined' ? options.hx : '',
                $existing_hx = typeof options.existingHx !== 'undefined' ? options.existingHx : '',
                $this_tab_list_items = $this_tab_list.children(".js-tablist__item"),
                $this_tab_list_links = $this_tab_list.find(".js-tablist__link");

            // Roles init
            // Tag ul.
            $this_tab_list.attr("role", "tablist");
            // Tag li.
            $this_tab_list_items.attr("role", "presentation");
            // Tag a.
            $this_tab_list_links.attr("role", "tab");

            // Classes init.
            $this_tab_list.addClass($tabs_prefix_classes + 'tabs__list');
            $this_tab_list_items.addClass($tabs_prefix_classes + 'tabs__item');
            $this_tab_list_links.addClass($tabs_prefix_classes + 'tabs__link');

            // Controls/tabindex attributes.
            $this_tab_list_links.each(function () {
                var $this = $(this),
                    $hx_generated_class = typeof options.tabsGeneratedHxClass !== 'undefined' ? options.tabsGeneratedHxClass : 'invisible',
                    $href = $this.attr("href"),
                    $controls = $($href),
                    $text = $this.text();

                if ($hx !== "") {
                    $controls.prepend('<' + $hx + ' class="' + $hx_generated_class + '" tabindex="0">' + $text + '</' + $hx + '>');
                }
                if ($existing_hx !== "") {
                    $controls.find($existing_hx + ':first-child').attr('tabindex', 0);
                }
                if (typeof $href !== "undefined" && $href !== "" && $href !== "#") {
                    $this.attr({
                        "aria-controls": $href.replace("#", ""),
                        "tabindex": -1,
                        "aria-selected": "false"
                    });
                }

                $this.removeAttr("href");

            });
        });

        // Tabs content.
        $(".js-tabcontent").attr({
                // Contents.
                "role": "tabpanel",
                // All hidden.
                "aria-hidden": "true"
                // "tabindex": 0.
            })
            .each(function () {
                var $this = $(this),
                    $this_id = $this.attr("id"),
                    $prefix_attribute = $("#label_" + $this_id).closest('.js-tablist').attr('data-tabs-prefix-class'),
                    $tabs_prefix_classes = typeof $prefix_attribute !== 'undefined' ? $prefix_attribute + '-' : '';
                // Label by link.
                $this.attr("aria-labelledby", "label_" + $this_id);

                $this.addClass($tabs_prefix_classes + 'tabs__content');
            });

        // Search if hash is ON tabs.
        if (hash !== "" && $("#" + hash + ".js-tabcontent").length !== 0) {
            // Display.
            $("#" + hash + ".js-tabcontent").removeAttr("aria-hidden");
            // Selection menu.
            $("#label_" + hash + ".js-tablist__link").attr({
                "aria-selected": "true",
                "tabindex": 0
            });
        }
        // Search if hash is IN tabs.
        if (hash !== "" && $("#" + hash).parents('.js-tabcontent').length) {
            var $this_hash = $("#" + hash),
                $tab_content_parent = $this_hash.parents('.js-tabcontent'),
                $tab_content_parent_id = $tab_content_parent.attr('id');

            $tab_content_parent.removeAttr("aria-hidden");
            // Selection menu.
            $("#label_" + $tab_content_parent_id + ".js-tablist__link").attr({
                "aria-selected": "true",
                "tabindex": 0
            });
        }

        // If no selected => select first.
        $tabs.each(function () {
            var $this = $(this),
                $tab_selected = $this.find('.js-tablist__link[aria-selected="true"]'),
                $first_link = $this.find(".js-tablist__link:first"),
                $first_content = $this.find(".js-tabcontent:first");

            if ($tab_selected.length === 0) {
                $first_link.attr({
                    "aria-selected": "true",
                    "tabindex": 0
                });
                $first_content.removeAttr("aria-hidden");
            }
        });

        // Events to catch.
        // Click on a tab link.
        $("body").on("click", ".js-tablist__link", function (event) {
                var $this = $(this),
                    $hash_to_update = $this.attr("aria-controls"),
                    $tab_content_linked = $("#" + $this.attr("aria-controls")),
                    $parent = $this.closest(".js-tabs"),
                    $all_tab_links = $parent.find(".js-tablist__link"),
                    $all_tab_contents = $parent.find(".js-tabcontent");

                // Manage aria select li parent and siblings.
                var $parent_item = $this.parent(),
                    $all_tab_li_items = $parent_item.siblings(".js-tablist__item");
                $all_tab_li_items.removeClass("active");
                $parent_item.addClass("active");

                // Aria selected false on all links.
                $all_tab_links.attr({
                    "tabindex": -1,
                    "aria-selected": "false"
                });

                // Add aria selected on $this.
                $this.attr({
                    "aria-selected": "true",
                    "tabindex": 0
                });

                // Add aria-hidden on all tabs contents.
                $all_tab_contents.attr("aria-hidden", "true");

                // Remove aria-hidden on tab linked.
                $tab_content_linked.removeAttr("aria-hidden");

                // Add active on tab content.
                $tab_content_linked.addClass("active");

                // Add fragment (timeout for transitions)
                setTimeout(function () {
                    history.pushState(null, null, location.pathname + location.search + '#' + $hash_to_update)
                }, 1000);

                event.preventDefault();
            })
            // Key down in tabs.
            .on("keydown", ".js-tablist", function (event) {

                var $parent = $(this).closest('.js-tabs'),
                    $activated = $parent.find('.js-tablist__link[aria-selected="true"]').parent(),
                    $last_link = $parent.find(".js-tablist__item:last-child .js-tablist__link"),
                    $first_link = $parent.find(".js-tablist__item:first-child .js-tablist__link"),
                    $focus_on_tab_only = false;

                // Some event should be activated only if the focus is on tabs (not on tabpanel).
                if ($(document.activeElement).is($parent.find('.js-tablist__link'))) {
                    $focus_on_tab_only = true;
                }

                // Catch keyboard event only if focus is on tab.
                if ($focus_on_tab_only && !event.ctrlKey) {
                    // Strike up or left in the tab.
                    if (event.keyCode == 37 || event.keyCode == 38) {
                        // If we are on first => activate last.
                        if ($activated.is(".js-tablist__item:first-child")) {
                            $last_link.click().focus();
                        }
                        // Else activate previous.
                        else {
                            $activated.prev().children(".js-tablist__link").click().focus();
                        }
                        event.preventDefault();
                    }
                    // Strike down or right in the tab.
                    else if (event.keyCode == 40 || event.keyCode == 39) {
                        // If we are on last => activate first.
                        if ($activated.is(".js-tablist__item:last-child")) {
                            $first_link.click().focus();
                        }
                        // Else activate next.
                        else {
                            $activated.next().children(".js-tablist__link").click().focus();
                        }
                        event.preventDefault();
                    }
                    else if (event.keyCode == 36) {
                        // Activate first tab.
                        $first_link.click().focus();
                        event.preventDefault();
                    }
                    else if (event.keyCode == 35) {
                        // Activate last tab.
                        $last_link.click().focus();
                        event.preventDefault();
                    }

                }

            })
            .on("keydown", ".js-tabcontent", function (event) {

                var $this = $(this),
                    $selector_tab_to_focus = $this.attr('aria-labelledby'),
                    $tab_to_focus = $("#" + $selector_tab_to_focus),
                    $parent_item = $tab_to_focus.parent(),
                    $parent_list = $parent_item.parent();

                // CTRL up/Left.
                if ((event.keyCode == 37 || event.keyCode == 38) && event.ctrlKey) {
                    $tab_to_focus.focus();
                    event.preventDefault();
                }
                // CTRL PageUp.
                if (event.keyCode == 33 && event.ctrlKey) {
                    $tab_to_focus.focus();

                    // If we are on first => activate last.
                    if ($parent_item.is(".js-tablist__item:first-child")) {
                        $parent_list.find(".js-tablist__item:last-child .js-tablist__link").click().focus();
                    }
                    // Else activate prev.
                    else {
                        $parent_item.prev().children(".js-tablist__link").click().focus();
                    }
                    event.preventDefault();
                }
                // CTRL PageDown.
                if (event.keyCode == 34 && event.ctrlKey) {
                    $tab_to_focus.focus();

                    // If we are on last => activate first.
                    if ($parent_item.is(".js-tablist__item:last-child")) {
                        $parent_list.find(".js-tablist__item:first-child .js-tablist__link").click().focus();
                    }
                    // Else activate next.
                    else {
                        $parent_item.next().children(".js-tablist__link").click().focus();
                    }
                    event.preventDefault();
                }

            })
            // Click on a tab link.
            .on("click", ".js-link-to-tab", function (event) {
                var $this = $(this),
                    $tab_to_go = $($this.attr('href')),
                    $button_to_click = $('#' + $tab_to_go.attr('aria-labelledby'));

                // Activate tabs.
                $button_to_click.click();
                // Give focus to the good button.
                setTimeout(function () {
                    $button_to_click.focus()
                }, 10);
            });

    }

});
