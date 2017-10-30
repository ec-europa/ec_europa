<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if (!empty($label)): ?>
    <span<?php print $atomium['attributes']['title']; ?>><?php print $label ?></span>
  <?php endif; ?>
  <?php print render($items); ?>
</div>
