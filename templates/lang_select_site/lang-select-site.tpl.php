<?php

/**
 * @file
 * Contains component file.
 */
?>
<div class="ecl-language-list ecl-language-list--overlay ecl-site-header__language-list">

  <div id="ecl-overlay-language-list" class="ecl-dialog__overlay ecl-dialog__overlay--blue" aria-hidden="true"></div>


  <div class="ecl-lang-select-sites ecl-link" data-ecl-dialog="ecl-dialog" id="ecl-lang-select-sites__overlay">
    <a href="<?php print $url; ?>" class="ecl-lang-select-sites__link">
      <span class="ecl-lang-select-sites__label"><?php print \render($label); ?></span>
      <span class="ecl-lang-select-sites__code">
      <span class="ecl-icon ecl-icon--language ecl-lang-select-sites__icon"></span>
      <span class="ecl-lang-select-sites__code-text"><?php print \render($code); ?></span>
    </span>
    </a>
  </div>

  <div class="ecl-dialog ecl-dialog--transparent ecl-dialog--wide" id="ecl-dialog" aria-labelledby="ecl-dialog-title" aria-describedby="ecl-dialog-description" aria-hidden="true" role="dialog">
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
                  <?php print \render($languages); ?>
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
