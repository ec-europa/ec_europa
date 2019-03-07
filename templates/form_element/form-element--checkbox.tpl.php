<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if ($element['#field_prefix']): ?>
    <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
  <?php endif; ?>
  <label<?php print $atomium['attributes']['label']; ?>>
    <?php print $element['#children']; ?><?php print render($label); ?>
  </label>
  <?php if ($element['#field_suffix']): ?>
    <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
  <?php endif; ?>
  <?php if (!empty($description)): ?>
    <p class="ecl-help-block"><?php print $element['#description']; ?></p>
  <?php endif; ?>
</div>
