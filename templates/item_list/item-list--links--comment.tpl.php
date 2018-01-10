<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!empty($variables['items'])): ?>
  <?php foreach ($variables['items'] as $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
<?php endif; ?>
