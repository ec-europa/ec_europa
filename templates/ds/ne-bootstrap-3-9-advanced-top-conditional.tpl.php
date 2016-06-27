<?php
/**
 * @file
 * Display Suite NE Bootstrap Three Columns Stacked.
 */

// Add sidebar classes so that we can apply the correct width in css.
// Second block is needed to activate display suite support on forms.
?>

<<?php print $layout_wrapper . $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])) : ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <!-- Page Header -->
  <div class="page-header<?php if (isset($header_back)) : print ' page-header--image';
 endif; ?>">
    <nav class="page-navigation" role="navigation">
      <div class="container-fluid">
        <?php print render($header_bottom); ?>
      </div>
    </nav>
    <div class="container-fluid page-header__hero-title">
      <div class="row padding-reset">
        <<?php print $left_header_wrapper; ?> class="col-lg-9 <?php print $left_header_classes; ?>">
          <?php print $left_header; ?>
        </<?php print $left_header_wrapper; ?>>

        <?php if (!empty($right_header)) : ?>
          <<?php print $right_header_wrapper; ?> class="col-lg-3 <?php print $right_header_classes; ?>">
            <?php print $right_header; ?>
          </<?php print $right_header_wrapper; ?>>
        <?php endif; ?>
      </div>
    </div>
  </div>

  <div class="page-content">

    <div class="container-fluid">

      <?php if (!empty($top_top) || !empty($local_tabs) || !empty($messages)) : ?>
        <div class="row">
          <section class="section section--content-top col-md-12 <?php print $top_top_classes; ?>">
            <?php if (!empty($local_tabs)) : ?>
              <?php print $local_tabs; ?>
            <?php endif; ?>
            <?php if (!empty($messages)) : ?>
              <?php print $messages; ?>
            <?php endif; ?>
            <?php print $top_top; ?>
          </section>
        </div>
      <?php endif; ?>

      <?php if ((isset($top_middle_left) && !empty($top_middle_left)) || (isset($top_middle_right) && !empty($top_middle_right))) : ?>
        <div class="row">

          <?php if (isset($top_middle_left) && !empty($top_middle_left)) : ?>
            <<?php print $top_middle_left_wrapper; ?> class="section section--content-top-middle-left col-lg-4 <?php print $top_middle_left_classes; ?>">
              <?php print $top_middle_left; ?>
          </<?php print $top_middle_left_wrapper; ?>>
          <?php endif; ?>

          <?php if (isset($top_middle_right) && !empty($top_middle_right)) : ?>
            <<?php print $top_middle_right_wrapper; ?> class="section section--content-top-middle-right col-lg-8 <?php print $top_middle_right_classes; ?>">
              <?php print $top_middle_right; ?>
            </<?php print $top_middle_right_wrapper; ?>>
          <?php endif; ?>

        </div>
      <?php endif; ?>

      <?php if ((isset($top_bottom_left) && !empty($top_bottom_left)) || (isset($top_bottom_right) && !empty($top_bottom_right))) : ?>
        <div class="row">

          <?php if (isset($top_bottom_left) && !empty($top_bottom_left)) : ?>
            <<?php print $top_bottom_left_wrapper; ?> class="section section--content-top-bottom-left col-lg-9 <?php print $top_bottom_left_classes; ?>">
            <?php print $top_bottom_left; ?>
            </<?php print $top_bottom_left_wrapper; ?>>
          <?php endif; ?>

          <?php if (isset($top_bottom_right) && !empty($top_bottom_right)) : ?>
            <<?php print $top_bottom_right_wrapper; ?> class="section section--content-top-bottom-right col-lg-3 <?php print $top_bottom_right_classes; ?>">
            <?php print $top_bottom_right; ?>
            </<?php print $top_bottom_right_wrapper; ?>>
          <?php endif; ?>

        </div>
      <?php endif; ?>

      <div class="row">

        <a id="main-content" tabindex="-1"></a>
        <?php if (isset($left) && !empty($left)) : ?>
          <<?php print $left_wrapper; ?> class="col-md-3 <?php print $left_classes; ?>">
            <?php print $left; ?>
          </<?php print $left_wrapper; ?>>
        <?php endif; ?>

        <section class="section <?php print (isset($left) && !empty($left) ? 'col-md-9 ' : 'col-md-12 ') . $central_classes; ?>">
          <?php print $central; ?>
        </section>

      </div>

    </div>

  </div>

</<?php print $layout_wrapper; ?>>

<?php if (!empty($drupal_render_children)) : ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
