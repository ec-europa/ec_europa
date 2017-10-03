<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php print render($logged_in_user); ?>
<ul<?php print $atomium['attributes']['wrapper']; ?>><?php print render($tree); ?></ul>
