<?php

/**
 * @file
 * Contains template file.
 */
?>

<div<?php print $attributes; ?>>
  <?php print render($small_description); ?>
  <?php print render($element['#children']); ?>
</div>
