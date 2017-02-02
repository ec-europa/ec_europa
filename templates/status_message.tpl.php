<?php

/**
 * @file
 * Contains the markup for the message block.
 */
?>
<div class="messages <?php print $message_classes; ?>">

  <?php if ($message_title): ?>
    <h3><?php print ($message_type ? '<span class="sr-only">' . $message_type . ': </span>' : '') . $message_title; ?></h3>
  <?php else: ?>
    <?php print ($message_type ? '<span class="sr-only">' . $message_type . ': </span>' : ''); ?>
  <?php endif; ?>

  <?php if ($message_body): ?>
    <?php print $message_body; ?>
  <?php endif; ?>

</div>
