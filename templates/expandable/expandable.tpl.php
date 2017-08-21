<?php

/**
 * @file
 * Contains template file.
 */
?>

<div<?php print $attributes; ?>>
  <?php print render($title); ?>
  <div<?php print $content_attributes; ?>>
    <?php print render($body); ?>
  </div>
</div>
