<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
    <div class="field__label"><?php print $label ?></div>
    <div class="field__items">
      <?php foreach ($items as $delta => $item) : ?>
          <div<?php print $atomium['attributes'][$delta]; ?>><?php print render($item); ?></div>
      <?php endforeach; ?>
    </div>
</div>
