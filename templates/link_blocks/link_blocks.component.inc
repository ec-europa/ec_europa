<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_link_blocks() {
  return array(
    'link_blocks' => array(
      'template' => 'link-blocks',
      'variables' => array(
        'items' => array(),
        'title' => NULL,

        'type' => 'ul',
        'attributes' => array(
          'class' => array(
            'ecl-link-block__list',
          ),
        ),
        'wrapper' => TRUE,
        'wrapper_attributes' => array(
          'class' => array(
            'ecl-link-block',
          ),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_link_blocks(array &$variables, $hook) {
  if (!empty($variables['items'])) {
    $num_items = count($variables['items']);
    $i = 0;

    foreach ($variables['items'] as $key => $item) {
      $variables['atomium']['attributes'][$key]->append('class', 'ecl-link-block__item');
      $i++;
      if ($i == 1) {
        $variables['atomium']['attributes'][$key]->append('class', 'first');
      }
      if ($i == $num_items) {
        $variables['atomium']['attributes'][$key]->append('class', 'last');
      }

      if (is_array($item) && isset($item['data'])) {
        $item += array('class' => array());
        $variables['atomium']['attributes'][$key]->append('class', $item['class']);
        $item['data'] += array(
          '#theme' => 'link',
          '#options' => array(
            'attributes' => array(
              'class' => array(
                'ecl-link',
                'ecl-link--standalone',
                'ecl-link-block__link',
              ),
            ),
          ),
        );
        $variables['items'][$key] = array(
          '#theme' => 'html_tag__' . $variables['theme_hook_original'],
          '#tag' => 'li',
          '#atomium' => array(
            'attributes' => array(
              'element' => $variables['atomium']['attributes'][$key],
            ),
          ),
          '#value' => $item['data'],
        );
      }

      if (is_string($item)) {
        $variables['items'][$key] = array(
          '#theme' => 'html_tag__' . $variables['theme_hook_original'],
          '#tag' => 'li',
          '#atomium' => array(
            'attributes' => array(
              'element' => $variables['atomium']['attributes'][$key],
            ),
          ),
          '#value' => $item,
        );
      }
      $variables['items'][$key] += array('#attributes' => array());
    }
  }

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['list']->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']->merge($variables['wrapper_attributes']);
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_link_blocks() {
  return array(
    'label' => 'Test link blocks',
    'description' => 'Test link-blocks.',
    'preview' => array(
      'title' => 'Title link blocks',
      'items' => array(
        array(
          'data' => array(
            '#theme' => 'link',
            '#text' => 'Home',
            '#path' => '/',
          ),
          'attributes' => array(
            '#class' => array(
              'miclsess',
            ),
          ),
        ),
        array(
          'data' => array(
            '#theme' => 'link',
            '#text' => 'News',
            '#path' => '/',
          ),
        ),
      ),
    ),
  );
}
