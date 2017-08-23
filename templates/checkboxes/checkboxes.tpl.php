<?php

/**
 * @file
 * Contains template file.
 */
?>

<div<?php print render($attributes); ?>>
  <?php print render($small_description); ?>
  <?php print render($element['#children']); ?>
</div>
