<?php

/**
 * @file
 * Template file for the language selector page.
 */
?>
<div class="ecl-language-list ecl-language-list--overlay">

  <div id="ecl-overlay-language-list" class="ecl-dialog__overlay ecl-dialog__overlay--blue"></div>

  <div class="ecl-dialog ecl-dialog--transparent ecl-dialog--wide" id="ecl-dialog" aria-labelledby="ecl-dialog-title" aria-describedby="ecl-dialog-description" role="dialog">
    <h3 id="ecl-dialog-title" class="ecl-heading ecl-heading--h3 ecl-u-sr-only">Dialog</h3>
    <div class="ecl-dialog__body">
      <section>
        <div class="">
          <div class="ecl-container">
            <div class="ecl-row">
              <div class="ecl-col-lg-8 ecl-offset-lg-2">
                <h2 lang="en" class="ecl-heading ecl-heading--h2 ecl-dialog__title">
                  <span class="ecl-icon ecl-icon--generic-lang"></span> Select your language
                </h2>
                <div class="ecl-row">
                <?php print render($page['content']); ?>
                <button class="ecl-message__dismiss ecl-message__dismiss--inverted">Close</button>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>

    </div>
  </div>
</div>
