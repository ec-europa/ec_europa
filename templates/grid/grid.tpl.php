<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
    <?php foreach ($rows as $columns): ?>
        <div class="ecl-row">
          <?php foreach ($columns as $item): ?>
              <div class="ecl-col">
                <?php print render($item); ?>
              </div>
          <?php endforeach; ?>
        </div>
    <?php endforeach; ?>
 </div>
