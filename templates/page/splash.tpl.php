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
 * - $splash_helper_text: Formatted html helper text.
 *
 * @see template_preprocess()
 * @see template_preprocess_splash()
 * @see template_process()
 */
?>
<nav class="splash-page__container">
  <h2 lang="<?php print $language_current; ?>"><span class="icon icon--generic-lang"></span> <?php print $header_text; ?></h2>

  <?php print $languages_list; ?>

  <?php if (isset($overlay_helper_text) || isset($splash_helper_text)): ?>
    <div class="splash-page__helper-text">

      <?php if (isset($overlay_helper_text)): ?>
        <div class="overlay-helper-text">
          <?php print $overlay_helper_text; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($splash_helper_text)): ?>
        <div class="splash-helper-text">
          <?php print $splash_helper_text; ?>
        </div>
      <?php endif; ?>

    </div>
  <?php endif; ?>
  <?php print l(t('Close'), '#', ['attributes' => ['class' => ['splash-page__btn-close']]]); ?>
</nav>
