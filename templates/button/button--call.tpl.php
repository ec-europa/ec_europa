<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $atomium['attributes']['element']->append('class', array('ecl-button--call')); ?>>
  <?php print \render($element['#value']); ?><?php print \render($element['#children']); ?>
</button>
