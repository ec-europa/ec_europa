<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
  <span class="ecl-tag__label"><?php print $label ?></span>
  <?php print render($items); ?>
</div>
