<?php

/**
 * @file
 * Contains template file.
 */
?>
<select<?php print $atomium['attributes']['element']->append('class', 'ecl-select')->setAttribute('id', $element['#id']); ?>><?php print form_select_options($element); ?></select>
