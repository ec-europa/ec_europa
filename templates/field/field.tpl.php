<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
    <div class="ecl-field__label"><?php print $label ?></div>
    <div class="ecl-field__body">
      <?php foreach ($items as $delta => $item) : ?>
          <div<?php print $attributes_item[$delta]; ?>><?php print render($item); ?></div>
      <?php endforeach; ?>
    </div>
</div>
