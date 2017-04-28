<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="ecl-container">
  <?php foreach ($rows as $row_number => $columns): ?>
    <div class="ecl-row">
    <?php foreach ($columns as $column_number => $item): ?>
      <div class="ecl-col">
        <?php print render($item); ?>
      </div>
    <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>
