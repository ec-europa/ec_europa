<?php

/**
 * @file
 * EC Europa's theme implementation of a set of radios button.
 *
 * Available variables:
 *   - 'attributes': HTML attributes of the container of the set;
 *   - '#children': The rendered child elements of an element;
 */
?>
<div<?php print $attributes; ?>>
  <?php if (!empty($description)): ?>
    <p<?php print $descr_attributes; ?>><?php print render($description); ?></p>
  <?php endif; ?>
  <?php print $element['#children']; ?>
</div>
