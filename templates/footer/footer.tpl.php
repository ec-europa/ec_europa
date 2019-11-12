<?php

/**
 * @file
 * Contains template file.
 */
?>
<footer class="ecl-footer">
  <div class="ecl-footer__custom">

    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-footer__column ecl-col-md">
          <?php print render($footer_left); ?>
        </div>
        <div class="ecl-footer__column ecl-col-md">
          <?php print render($footer_middle); ?>
        </div>
        <div class="ecl-footer__column ecl-col-md">
          <?php print render($footer_right); ?>
        </div>
      </div>
    </div>

  </div>
  <div class="ecl-footer__corporate">
    <div class="ecl-footer__corporate-top">
      <div class="ecl-container">
        <div class="ecl-row">
          <div class="ecl-footer__column ecl-col-md">
            <?php print render($footer_corporate_left); ?>
          </div>
          <div class="ecl-footer__column ecl-col-md">
            <?php print render($footer_corporate_middle); ?>
          </div>
          <div class="ecl-footer__column ecl-col-md">
            <?php print render($footer_corporate_right); ?>
          </div>
        </div>
      </div>
    </div>
    <div class="ecl-footer__corporate-bottom">
      <div class="ecl-container">
        <div class="ecl-row">
          <div class="ecl-col">
            <?php print render($footer_ec); ?>
          </div>
        </div>
      </div>
    </div>

  </div>
</footer>