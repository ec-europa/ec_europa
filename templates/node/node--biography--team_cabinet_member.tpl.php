<?php
/**
 * @file
 * Define the display of a custom view mode.
 */
  $content['body']['#title'] = t('Responsibilities');
?>

<div class="listing__top">
  <?php print render($content['field_biography_tagline']); ?>
  <?php print render($title_prefix); ?>
  <h3 class="listing__title--grey-dark">
    <?php print render($title); ?>
  </h3>
  <?php print render($title_suffix); ?>
  <?php print render($content['field_biography_portrait']); ?>
  <div class="listing__top__footer">
    <?php print render($content['field_biography_email']); ?>
    <?php print render($content['field_biography_phone']) ?>
    <?php print render($content['field_social_networks']); ?>
  </div>
</div>
<div class="listing__bottom">
  <?php print render($content['body']); ?>
</div>
