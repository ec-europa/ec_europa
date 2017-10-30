<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php // @todo: remove the 'style="float:right"' after the update of ecl. ?>
<nav class="ecl-navigation-list-wrapper ecl-u-f-r" style="float:right">
    <h2 class="ecl-u-sr-only">User menu</h2>
    <ul<?php print $atomium['attributes']['wrapper']; ?>><?php print render($tree); ?></ul>
</nav>
