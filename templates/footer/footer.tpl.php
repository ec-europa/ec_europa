<?php

/**
 * @file
 * Contains template file.
 */
?>
<footer class="ecl-footer">
  <?php if ($footer_left || $footer_middle || $footer_right): ?>
  <div class="ecl-footer__site-identity">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm ecl-footer__column">
          <?php print \render($footer_left); ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php print \render($footer_middle); ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php print \render($footer_right); ?>
        </div>
      </div>
    </div>
  </div>
  <?php endif; ?>

  <div class="ecl-footer__site-corporate">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm ecl-footer__column">
          <?php print \render($footer_corporate_left); ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php print \render($footer_corporate_middle); ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php print \render($footer_corporate_right); ?>
        </div>
      </div>
    </div>
  </div>

  <div class="ecl-footer__ec">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm">
          <?php print \render($footer_ec); ?>
        </div>
      </div>
    </div>
  </div>
</footer>
