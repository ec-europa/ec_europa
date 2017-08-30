<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
  <span<?php print $title_attributes; ?>><?php print $label ?></span>
  <?php print render($items); ?>
</div>
