<?php

/**
 * @file
 * Contains template file.
 */
?>

<div class="ecl-form-group">
    <label<?php print $atomium['attributes']['label']->append('class', 'ecl-form-label')->setAttribute('id', $element['#id']); ?>>
      <?php print render($label); ?>
    </label>
    <select<?php print $atomium['attributes']['element']->append('class', 'ecl-select')->setAttribute('id', $element['#id']); ?>><?php print form_select_options($element); ?></select>
</div>
