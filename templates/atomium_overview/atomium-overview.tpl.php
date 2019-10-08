<?php

/**
 * @file
 * Contains template file.
 */
?>
<h2 class="ecl-heading ecl-heading--h2"><?php print t('Components selector (&plusmn;@count)', array('@count' => \count($definitions))); ?></h2>

<div>
    <select class="ecl-select" onchange="location = this.options[this.selectedIndex].value;">
        <option value=""><?php print t('Choose a component'); ?></option>
        <?php foreach ($definitions as $name => $definition): ?>
          <option value="#<?php print $name; ?>"><?php print $definition['label']; ?></option>
        <?php endforeach; ?>
    </select>
    <p class="ecl-help-block">Choose a component.</p>
</div>

<h2 class="ecl-heading ecl-heading--h2"><?php print t('EC Europa components'); ?></h2>

<?php foreach ($definitions as $name => $definition): ?>
  <a name="<?php print $name; ?>"></a>
  <a class="ecl-u-f-r ecl-link" href="#top">Back to top</a>
  <h3 class="ecl-heading ecl-heading--h3"><?php print $definition['label']; ?></h3>
  <fieldset class="ecl-fieldset">
    <legend><?php print t('Preview'); ?></legend>
    <div>
      <?php if (isset($definition['description'])): ?>
        <p><?php print $definition['description']; ?></p>
      <?php endif; ?>
      <?php if (isset($definition['preview'])): ?>
        <div class="ecl-u-clearfix">
          <?php print render($definition['preview']); ?>
        </div>
      <?php endif; ?>
      <?php if (isset($definition['form'])): ?>
        <div class="ecl-u-clearfix">
          <?php print render($definition['form']); ?>
        </div>
      <?php endif; ?>
    </div>
  </fieldset>
  <hr/>
<?php endforeach; ?>
