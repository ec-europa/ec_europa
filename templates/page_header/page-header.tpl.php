<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="ecl-page-header">
  <?php print render($breadcrumb); ?>
  <div class="ecl-page-header__body">
      <div class="ecl-container">
        <?php if (!empty($identity)): ?>
            <div class="ecl-page-header__identity">
              <?php print render($identity); ?>
            </div>
        <?php endif; ?>
        <?php if(!$ec_europa_basic_header): ?>
          <?php if (!empty($meta)): ?>
            <div class="ecl-page-header__meta">
              <?php print render($meta); ?>
            </div>
          <?php endif; ?>
          <div class="ecl-page-header__title">
            <h1 class="ecl-heading ecl-heading--h1 ecl-u-color-white">Business, Economy, Euro</h1>
          </div>
          <?php if (!empty($introduction)): ?>
            <div class="ecl-page-header__intro">
              <p class="ecl-paragraph ecl-paragraph--l">
                <?php print render($introduction); ?>
              </p>
            </div>
          <?php endif; ?>
        <?php endif; ?>
      </div>
  </div>
</div>
