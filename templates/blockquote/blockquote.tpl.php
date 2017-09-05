<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
    <blockquote class="ecl-blockquote__quote">
        <p class="ecl-blockquote__body"><?php print render($body); ?></p>
    </blockquote>
    <div class="ecl-blockquote__author"><?php print render($author); ?></div>
</div>
