<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $atomium['attributes']['element']->append('class', array('ecl-button--primary', 'ecl-u-mt-s'))->remove('class', 'ecl-button--form'); ?>>
  <?php print render($element['#value']); ?><?php print render($element['#children']); ?>
</button>
