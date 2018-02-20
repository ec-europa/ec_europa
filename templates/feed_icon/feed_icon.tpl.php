<?php

/**
 * @file
 * Theme implementation of the rss feed link.
 *
 * Available variables:
 *
 * Page content:
 * - $feed_icon (array): An array containing the feed icon.
 */
?>
<div class="ecl-rss-links">
  <span class="ecl-rss-links__label"><?php print t('Get updates')?>:</span>
  <?php print render($feed_icon); ?>
</div>

