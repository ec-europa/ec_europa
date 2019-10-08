<?php

/**
 * @file
 * Splash screen.
 */
?>

<section>
    <a id="main-content" tabindex="-1"></a>
    <header class="ecl-u-bg-default ecl-u-pv-l" role="banner">
        <div class="ecl-container">
          <?php print render($logo); ?>
        </div>
    </header>
    <div class="ecl-u-bg-primary ecl-u-pv-xl">
        <div class="ecl-container">
            <div class="ecl-row">
                <div class="ecl-col-lg-8 ecl-offset-lg-2">
                  <?php print render($splash); ?>
                </div>
            </div>
        </div>
    </div>
</section>
