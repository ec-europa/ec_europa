<?php

/**
 * @file
 * Contains template file.
 */
?>
<nav<?php print $attributes; ?>>
  <span class="ecl-sr-only"><?php print render($here); ?></span>
  <ol class="ecl-breadcrumbs__segments-wrapper">
    <?php print render($easy_breadcrumb); ?>
  </ol>
</nav>
