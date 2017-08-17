<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print render($attributes); ?>>
  <span class="ecl-tag_label"><?php print $label ?></span>
  <?php foreach ($items as $delta => $item) : ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
</div>
