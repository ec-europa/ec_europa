<?php

/**
 * @file
 * Contains template file.
 */
?>
<fieldset<?php print $atomium['attributes']['wrapper']->append('class', 'ecl-fieldset'); ?>>
  <?php if ($legend): ?>
    <?php print \render($legend); ?>
  <?php endif; ?>
    <div class="fieldset-wrapper">
      <?php print \render($description); ?>
      <?php print \render($element['#children']); ?>
    </div>
</fieldset>
