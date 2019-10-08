<?php

/**
 * @file
 * Contains template file.
 */
?>
<nav<?php print $atomium['attributes']['wrapper']; ?>>
  <span class="ecl-u-sr-only"><?php print render($here); ?></span>
  <ol class="ecl-breadcrumbs__segments-wrapper">
    <?php print render($easy_breadcrumb); ?>
  </ol>
</nav>
