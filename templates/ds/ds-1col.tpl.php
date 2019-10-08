<?php

/**
 * @file
 * Display Suite 1 column template.
 *
 * @TODO update once new grid style is defined.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ecl-container <?php print $classes; ?>">

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ecl-row <?php print $classes; ?>">

<?php print $ds_content; ?>

</<?php print $ds_content_wrapper; ?>>
</<?php print $layout_wrapper; ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
