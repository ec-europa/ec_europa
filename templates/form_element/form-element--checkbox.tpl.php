<?php

/**
 * @file
 * Contains template file.
 */
?>

<label<?php print $attributes; ?>>
    <?php if ($element['#field_prefix']): ?>
      <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
    <?php endif; ?>
      <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
      <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
    <?php endif; ?>
    <?php print render($label); ?>
</label>
