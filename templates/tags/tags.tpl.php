<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
  <?php if (!empty($label)): ?>
    <span<?php print $title_attributes; ?>><?php print $label ?></span>
  <?php endif; ?>
  <?php print render($tags); ?>
</div>
