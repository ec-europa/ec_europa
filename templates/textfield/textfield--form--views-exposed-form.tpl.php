<?php

/**
 * @file
 * Contains template file.
 */
?>
<input<?php print $atomium['attributes']['element']->append('class', "ecl-text-input")->append('id', $element['#id']); ?>/><?php print render($suffix); ?>
