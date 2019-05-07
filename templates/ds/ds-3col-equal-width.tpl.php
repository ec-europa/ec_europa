<?php

/**
 * @file
 * Display Suite 3 column equal width template.
 *
 * @TODO update once new grid style is defined.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ecl-container <?php print $classes; ?>">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ecl-row <?php print $classes; ?>">

    <<?php print $left_wrapper ?> class="ecl-col<?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper ?>>

    <<?php print $middle_wrapper ?> class="ecl-col<?php print $middle_classes; ?>">
      <?php print $middle; ?>
    </<?php print $middle_wrapper ?>>

    <<?php print $right_wrapper ?> class="ecl-col<?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper ?>>

  </<?php print $ds_content_wrapper ?>>
</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
