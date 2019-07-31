<?php

/**
 * @file
 * Contains template file.
 */
?>

<div<?php print $atomium['attributes']['wrapper']; ?>>
  <p<?php print $atomium['attributes']['description']; ?>><?php print \render($small_description); ?></p>
  <?php print \render($element['#children']); ?>
</div>
