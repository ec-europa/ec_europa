<?php

/**
 * @file
 * Default implementation of the splash page content.
 *
 * Available variables:
 * - $close_button: unformatted close button.
 * - $languages_list: the language list.
 * - $languages_list_array: unformated array of languages.
 * - $languages_blacklist: unformated array of blacklisted language codes.
 *
 * @see template_preprocess()
 * @see template_preprocess_splash()
 * @see template_process()
 */
?>

<div<?php print $atomium['attributes']['wrapper']; ?>><?php print render($languages_list); ?></div>
