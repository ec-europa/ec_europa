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

<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if (!empty($description)): ?>
    <p<?php print $atomium['attributes']['description']; ?>><?php print render($description); ?></p>
  <?php endif; ?>
  <?php print $element['#children']; ?>
</div>
