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
<section>
  <div class="">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-lg-8 ecl-offset-lg-2">
          <h2 lang="en" class="ecl-heading ecl-heading--h2 ecl-dialog__title">
            <span class="ecl-icon ecl-icon--generic-lang"></span><?php print t('Select your language'); ?>
          </h2>
          <div class="ecl-row">
            <?php print render($language_selector_site_language_list); ?>
            <button class="ecl-message__dismiss ecl-message__dismiss--inverted">Close</button>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
