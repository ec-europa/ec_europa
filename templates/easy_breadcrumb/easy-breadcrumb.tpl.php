<?php

/**
 * @file
 * Contains template file.
 */
?>
<div style="background-color: #004494; padding: 5px 15px 15px; float: left; width: 100%;">
<nav id="breadcrumb" class="breadcrumb" role="navigation" aria-label="breadcrumbs">
  <span class="element-invisible"><?php echo t('You are here'); ?></span>
  <ol class="breadcrumb__segments-wrapper">
    <?php print render($easy_breadcrumb); ?>
  </ol>
</nav>
</div>
