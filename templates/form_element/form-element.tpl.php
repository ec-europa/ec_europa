<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']->append('class', 'ecl-u-mt-m'); ?>>
  <?php if ('before' == $element['#title_display'] || 'invisible' == $element['#title_display']): ?>
    <?php print render($label); ?>
    <?php if ($element['#field_prefix']): ?>
      <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
      <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ('after' == $element['#title_display']): ?>
    <?php if ($element['#field_prefix']): ?>
      <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
    <?php endif; ?>
      <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
      <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
    <?php endif; ?>
    <?php print render($label); ?>
  <?php endif; ?>

  <?php if ('none' == $element['#title_display'] || 'attribute' == $element['#title_display']): ?>
    <?php if ($element['#field_prefix']): ?>
      <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
    <?php endif; ?>
      <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
      <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
    <?php endif; ?>
  <?php endif; ?>

  <?php if (!empty($description)): ?>
    <p class="ecl-help-block"><?php print $element['#description']; ?></p>
  <?php endif; ?>
</div>
