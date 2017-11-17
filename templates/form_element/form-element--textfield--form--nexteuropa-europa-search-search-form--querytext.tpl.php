<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <label class="ecl-search-form__textfield-wrapper">
    <?php print render($label); ?>
    <?php print $element['#children']; ?>
  </label>
</div>
