<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
  <?php if ($element['#field_prefix']): ?>
      <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
  <?php endif; ?>
    <label<?php print $label_tag_attributes; ?>>
      <?php print $element['#children']; ?>
      <?php print render($label); ?>
    </label>
  <?php if ($element['#field_suffix']): ?>
      <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
  <?php endif; ?>
</div>
