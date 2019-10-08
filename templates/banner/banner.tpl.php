<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="banner banner--quote">
    <div class="banner__quote">
        <blockquote class="ecl-blockquote blockquote blockquote--small">
            <span class="blockquote__open"></span>
            <?php print render($quote); ?>
            <span class="blockquote__close"></span>
        </blockquote>
    </div>
    <span class="banner__author">
      <?php print render($author); ?>
    </span>
</div>
