<?php
/**
 * @file
 * Display Suite NE Bootstrap Two Columns Stacked.
 */

  // Add sidebar classes so that we can apply the correct width in css.
  // Second block is needed to activate display suite support on forms.
?>

<div <?php print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])) : ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <a href="<?php print $node_url; ?>" class="listing__item-link">
    <h3 class="listing__title"><?php print $main; ?></h3>
  </a>

  <?php if (!empty($drupal_render_children)) : ?>
    <?php print $drupal_render_children; ?>
  <?php endif; ?>
</div>
