<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php foreach ($status_messages['status_messages'] as $key => $status_message): ?>
  <div<?php print $atomium['attributes']['status-' . $key]; ?>>
    <span class="ecl-u-sr-only"><?php print \render($status_message['status_heading']); ?></span>
    <button type="button" class="ecl-message__dismiss" aria-label="Dismiss this alert">&times;</button>
    <?php print \render($status_message['messages']); ?>
  </div>
<?php endforeach; ?>
