<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $atomium['attributes']['element']->append('class', 'ecl-button--primary')->append('class', 'ecl-button--block')->append('class', 'ecl-u-mt-s'); ?>>
  <?php print render($element['#value']); ?><?php print render($element['#children']); ?>
</button>
