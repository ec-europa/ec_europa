<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php print render($prefix); ?><input<?php print $atomium['attributes']['element']->append('class', 'ecl-text-input')->append('id', $element['#id']); ?>/><?php print render($suffix); ?>
