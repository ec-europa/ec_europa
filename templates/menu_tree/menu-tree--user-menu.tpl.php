<?php

/**
 * @file
 * Contains template file.
 */
?>
<nav class="ecl-navigation-list-wrapper ecl-u-f-r">
    <h2 class="ecl-u-sr-only">User menu</h2>
    <ul<?php print $atomium['attributes']['wrapper']; ?>><?php print render($tree); ?></ul>
</nav>
