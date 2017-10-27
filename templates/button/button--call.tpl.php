<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $atomium['attributes']['element']->append('class', array('ecl-button--call', 'ecl-button--caret-right')); ?>>
  <?php print render($element['#value']); ?><?php print render($element['#children']); ?>
</button>
