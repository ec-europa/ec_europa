<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $atomium['attributes']['element']->append('class', array('ecl-button--facet-close','ecl-tag__item')); ?>>
  <?php print render($element['#value']); ?><?php print render($element['#children']); ?>
</button>
