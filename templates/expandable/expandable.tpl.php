<?php

/**
 * @file
 * Contains template file.
 */
?>

<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php print \render($title); ?>
  <div<?php print $atomium['attributes']['content']; ?>>
    <?php print \render($body); ?>
  </div>
</div>
