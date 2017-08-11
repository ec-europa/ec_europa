<?php

/**
 * @file
 * EC Europa's theme implementation of a set of radios button.
 *
 * Available variables:
 *   - 'attributes': HTML attributes of the container of the set;
 *   - 'small_description': Small description compliant with WAI rules.
 *     By default, it is a concatenation of the static string and the title of
 *     the form element.
 *   - '#children': The rendered child elements of an element;
 */
?>

<div<?php print $attributes; ?>>
  <?php if (!empty($small_description)): ?>
    <p<?php print $descr_attributes; ?>><?php print render($small_description); ?></p>
  <?php endif; ?>
  <?php print $element['#children']; ?>
</div>
