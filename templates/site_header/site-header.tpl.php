<?php

/**
 * @file
 * Contains component file.
 */
?>
<header class="ecl-site-header" role="banner">
  <div class="ecl-site-switcher">
    <div class="ecl-container">
      <?php print render($menu); ?>
    </div>
  </div>
  <div class="ecl-container ecl-site-header__banner">
    <?php print render($logo); ?>
    <?php print render($site_slogan); ?>
    <?php print render($lang_select_site); ?>
    <?php print render($search_bar); ?>
  </div>
</header>
