<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="ecl-page-header ecl-page-header--default">
  <div class="ecl-container">
    <?php print render($breadcrumb); ?>
    <div class="ecl-page-header__body">
      <?php if (!empty($identity)): ?>
        <div class="ecl-page-header__identity">
          <?php print render($identity); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($meta)): ?>
        <div class="ecl-page-header__meta">
          <?php print render($meta); ?>
        </div>
      <?php endif; ?>
      <?php if (!$ec_europa_basic_header): ?>
        <div class="ecl-page-header__title">
          <h1 class="ecl-heading ecl-heading--h1 ecl-u-color-white">
              <?php print render($title); ?>
          </h1>
        </div>
        <?php if (!empty($introduction)): ?>
          <p class="ecl-page-header__intro">
            <?php print render($introduction); ?>
          </p>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
