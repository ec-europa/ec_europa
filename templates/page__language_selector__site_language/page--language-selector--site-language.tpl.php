<?php

/**
 * @file
 * Template file for the language selector page.
 */
?>
<div class="ecl-language-list ecl-language-list--overlay">

  <div id="ecl-overlay-language-list" class="ecl-dialog__overlay ecl-dialog__overlay--blue"></div>

  <div class="ecl-dialog ecl-dialog--transparent ecl-dialog--wide" id="ecl-dialog" aria-labelledby="ecl-dialog-title" aria-describedby="ecl-dialog-description" role="dialog">
    <h3 id="ecl-dialog-title" class="ecl-heading ecl-heading--h3 ecl-u-sr-only">Dialog</h3>
    <div class="ecl-dialog__body">
      <?php print render($page['content']); ?>
    </div>
  </div>
</div>
