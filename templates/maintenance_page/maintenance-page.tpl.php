<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html>
<html<?php print $atomium['attributes']['html'];?>>
<head<?php print $atomium['attributes']['head'];?>>
  <meta charset="utf-8"/>
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body<?php print $atomium['attributes']['body'];?>>
<div class="ecl-skip-link__wrapper" id="skip-link">
  <a href="#main-content" class="ecl-skip-link"><?php print t('Skip to main content'); ?></a>
</div>
<?php if (!empty($page['header_top'])): ?>
  <section class="header-top">
    <div class="ecl-container">
      <?php print render($page['header_top']); ?>
    </div>
  </section>
<?php endif; ?>

<?php print render($site_header); ?>
<?php print render($page['header']); ?>

<section class="main-content">
  <?php print render($page_header); ?>

  <?php if (!empty($page['navigation'])): ?>
    <?php print render($page['navigation']); ?>
  <?php endif; ?>

  <div class="ecl-container ecl-u-mv-l">
    <?php if (!empty($page['highlighted'])): ?>
      <div class="highlighted"><?php print render($page['highlighted']); ?></div>
    <?php endif; ?>

    <?php if (!empty($messages)): ?>
      <?php print render($messages); ?>
    <?php endif; ?>
  </div>

  <!-- Utility sections -->
  <?php if (!empty($page['utility'])): ?>
    <div class="utility">
      <div class="ecl-container">
        <?php print render($page['utility']); ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="page-content">
    <div class="ecl-container ecl-u-mv-l">
      <?php if (!empty($page['content_top'])): ?>
        <a id="top-content" tabindex="-2"></a>
        <div class="content_top">
          <?php print render($page['content_top']); ?>
        </div>
      <?php endif; ?>
      <a id="main-content" tabindex="-1"></a>
      <h1 class="ecl-heading ecl-heading--h1"><?php print render($title); ?></h1>

      <!-- Generic sections -->
      <div class="ecl-container">
        <div class="ecl-row">
          <div class="ecl-col">
            <?php if (!empty($tabs)): ?>
              <?php print render($tabs); ?>
            <?php endif; ?>

            <?php if (!empty($page['help'])): ?>
              <?php print render($page['help']); ?>
            <?php endif; ?>

            <?php if (!empty($action_links)): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>
          </div>
        </div>
      </div>

      <div class="ecl-row">
        <div class="ecl-col">
          <?php if (!empty($page['sidebar_first'])): ?>
            <aside class="ecl-col-sm-3" role="complementary">
              <?php print render($page['sidebar_first']); ?>
            </aside> <!-- /#sidebar-first -->
          <?php endif; ?>

          <section class="section <?php print $content_column_class; ?>">
            <?php print render($content); ?>

            <?php print render($page['content_bottom']); ?>
          </section>

          <?php if (!empty($page['sidebar_second'])): ?>
            <aside class="ecl-col-sm-3" role="complementary">
              <?php print render($page['sidebar_second']); ?>
            </aside>  <!-- /#sidebar-second -->
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
</section>

<?php print render($footer); ?>

</body>
</html>
