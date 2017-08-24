<?php

/**
 * @file
 * Contains template file.
 */
?>
<textarea<?php print $attributes; ?>><?php print check_plain(render($element['#value'])); ?></textarea>
