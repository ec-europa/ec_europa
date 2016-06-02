<?php
/**
 * @file
 * Display Suite NE Bootstrap Two Columns Stacked.
 */

  // Add sidebar classes so that we can apply the correct width in css.
  // Second block is needed to activate display suite support on forms.
?>
<?php /*
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <<?php print $main_wrapper; ?> class="column-main <?php print $main_classes; ?>">
    <?php print $main; ?>
  </<?php print $main_wrapper; ?>>
</<?php print $layout_wrapper ?>>
 */?>

<div class="listing listing--navigation">

  <a href="<?php print url($node->path['source']); ?>" class="listing__item-link">
    <h2 class="listing__section-title">
      <?php print $title; ?>
    </h2>

    <?php if ($description && !$children): ?>
      <p class="listing__description">
        <?php print $description; ?>
      </p>
    <?php endif; ?>
  </a>

  <?php if ($children): ?>
    <?php print $children; ?>
  <?php endif; ?>

  <?php if (($children || $description) && $links): ?>
    <hr class="listing__separator">
  <?php endif; ?>

  <?php if ($links): ?>
    <?php print $links; ?>
  <?php endif; ?>

</div>