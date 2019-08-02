<?php

/**
 * @file
 * Contains template file.
 */
?>
<textarea<?php print $atomium['attributes']['element']; ?>><?php print \render($element['#value']); ?></textarea>
