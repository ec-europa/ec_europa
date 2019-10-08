<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($title): ?>
  <div class="ecl-message__title"><?php print render($title); ?></div>
<?php endif; ?>

<?php if (!empty($variables['items'])): ?>
  <?php if ($type): ?>
    <<?php print $type; ?><?php print $atomium['attributes']['list']; ?>>
  <?php endif; ?>
  <?php print render($variables['items']); ?>
  <?php if ($type): ?>
    </<?php print $type; ?>>
  <?php endif; ?>
<?php endif; ?>
