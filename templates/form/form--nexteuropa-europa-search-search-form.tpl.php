<?php

/**
 * @file
 * Contains template file.
 */
?>
<form<?php print $atomium['attributes']['element']->append('class', array('ecl-search-form', 'ecl-site-header__search')); ?>>
  <?php print render($element['#children']); ?>
</form>
