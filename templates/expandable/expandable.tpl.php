<?php

/**
 * @file
 * Contains template file.
 */
?>

<div>
  <?php print render($link); ?>
  <div<?php print $content_attributes; ?>>
    <?php print render($body); ?>
  </div>
</div>
