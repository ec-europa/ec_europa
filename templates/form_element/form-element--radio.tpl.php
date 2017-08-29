<?php

/**
 * @file
 * EC Europa's theme implementation for a form element of a radio button.
 *
 * Available variables:
 *  - '#children': Array with the radio button tag definition;
 *  - '#description': The description of the form element;
 *  - '#field_prefix': string that is placed directly in front of the form
 *    element;
 *  - '#field_suffix': string that is placed directly after the form
 *    element;
 *  - '#id': string value of the form element id;
 *  - '#name': string value of the form element name;
 *  - '#required': Indicates whether or not the element is required.,
 *  - '#title': string value of the form element title that is used to build
 *    the radio label;
 *    Note: The label is included in the radio button display (see radio
 *          component)
 *  - '#title_display': NOT SUPPORTED BY EC Europa theme, it indicates how the
 *    label should be rendered;
 *  - '#type': string used to determine the type of form element.
 *
 * @see template_preprocess()
 * @see template_preprocess_form_element__radio()
 * @see template_process()
 */
?>
<div<?php print $attributes; ?>>
  <?php if ($element['#field_prefix']): ?>
      <span class="field-prefix"><?php render($element['#field_prefix']); ?></span>
  <?php endif; ?>
    <label<?php print $label_tag_attributes; ?>><?php print $element['#children']; ?><?php print render($label); ?></label>
  <?php if ($element['#field_suffix']): ?>
      <span class="field-suffix"><?php render($element['#field_suffix']); ?></span>
  <?php endif; ?>
</div>
