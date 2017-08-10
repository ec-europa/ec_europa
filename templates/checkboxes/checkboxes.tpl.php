<?php

/**
 * @file
 * Contains template file.
 */
?>

<div<?php print $attributes; ?>>
  <?php if (!empty($small_description)): ?>
      <p<?php print $descr_attributes; ?>><?php print render($small_description); ?></p>
  <?php endif; ?>
  <?php print $element['#children']; ?>
</div>
