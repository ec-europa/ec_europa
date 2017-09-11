<?php

/**
 * @file
 * EC Europa's theme implementation for form element label of radio button.
 *
 * Available variables:
 *  - 'title': string value of the form element title;
 *  - 'required': Element indicated if the radio element is required;
 *
 * @see template_preprocess()
 * @see template_preprocess_form_element_label()
 * @see template_process()
 */
?>

<span<?php print $attributes; ?>>
  <?php print render($form_element_label['title']); ?>
  <?php print render($form_element_label['required']); ?>
</span>
