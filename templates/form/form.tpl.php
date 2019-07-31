<?php

/**
 * @file
 * Contains template file.
 */
?>
<form<?php print $atomium['attributes']['element']->append('class', 'ecl-form'); ?>>
  <?php print \render($element['#children']); ?>
</form>
