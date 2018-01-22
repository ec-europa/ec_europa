<?php

/**
 * @file
 * Default implementation of the language selector.
 *
 * Available variables:
 * - $languages_list: the language list.
 * - $icon: optional language icon.
 * - $close_button: optional close button.
 *
 * @see template_preprocess()
 * @see template_preprocess_splash()
 * @see template_process()
 */
?>
<?php print render($language_selector_site_language_list); ?>
