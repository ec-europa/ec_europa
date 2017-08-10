<?php

/**
 * @file
 * EC Europa's theme implementation to display a radio button.
 *
 * Available variables:
 *  - 'label_tag_attributes': Array with the attributes definition for the
 *    label HTML tag;
 *    Note: it is set in ec_europa_preprocess_radio()
 *  - 'attributes': Array with the attributes definition for the radio button
 *    HTML tag;
 *  - 'label': Array with the definition of the radio button rendition.
 *    Note: it is set in ec_europa_preprocess_radio()
 *
 * @see ec_europa_preprocess_radio()
 * @see template_preprocess()
 * @see template_preprocess_radio()
 * @see template_process()
 */
?>
<input<?php print $attributes; ?>/>
