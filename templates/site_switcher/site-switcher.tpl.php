<?php

/**
 * @file
 * Contains component file.
 */
?>

<div<?php print $attributes; ?>>
  <ul class="ecl-site-switcher__list ecl-container">
    <li class="ecl-site-switcher__option<?php $link_1['selected'] ? print ' ecl-site-switcher__option--is-selected' : ''; ?>"><a class="ecl-link ecl-site-switcher__link" href="<?php print $link_1['url']; ?>"><?php print $link_1['title']; ?></a></li>
    <li class="ecl-site-switcher__option<?php $link_2['selected'] ? print ' ecl-site-switcher__option--is-selected' : ''; ?>"><a class="ecl-link ecl-site-switcher__link" href="<?php print $link_2['url']; ?>"><?php print $link_2['title']; ?></a></li>
  </ul>
</div>
