<?php

/**
 * @file
 * Contains template file.
 */
?>

<div>
  <?php print render($link); ?>
  <div id="<?php print $id; ?>" aria-labelledby="<?php print $id; ?>-button" aria-hidden="true">
    <?php print $body; ?>
  </div>
</div>
