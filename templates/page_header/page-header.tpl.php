<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="ecl-page-header">
  <?php print render($breadcrumb); ?>
  <div class="ecl-page-header__body">
      <?php if (!empty($identity)): ?>
        <div class="ecl-container">
            <div class="ecl-page-header__identity">
              <?php print render($identity); ?>
            </div>
        </div>
      <?php endif; ?>
      <?php if (!empty($meta)): ?>
        <div class="ecl-page-header__meta">
          <?php print render($meta); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($introduction)): ?>
        <div class="ecl-page-header__intro">
          <p class="ecl-paragraph ecl-paragraph--l">
            <?php print render($introduction); ?>
          </p>
        </div>
      <?php endif; ?>
  </div>
</div>
