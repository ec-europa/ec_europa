<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_search_bar() {
  return array(
    'label' => 'Search bar',
    'description' => 'Search bar.',
    'dependencies' => array('nexteuropa_europa_search'),
  );
}

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_search_bar() {
  return array(
    'search_bar' => array(
      'template' => 'search-bar',
      'variables' => array(
        'search_form' => NULL,
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 *
 * The final display of search bar is managed by this component and a variant
 * of the form_element component.
 *
 * @see _ec_europa_preprocess_form_element__QueryText()
 * @see _ec_europa_preprocess_textfield__QueryText()
 */
function ec_europa_preprocess_search_bar(array &$variables, $hook) {
  if (!module_exists('nexteuropa_europa_search')) {
    return;
  }

  // Generate the search form.
  $variables['search_form'] = drupal_get_form('nexteuropa_europa_search_search_form');

  $variables['atomium']['attributes']['search_form']->setAttributes($variables['attributes']);
  $variables['atomium']['attributes']['search_form']->append('class', 'ecl-search-form');

  // Add CSS to the form tag.
  $variables['search_form']['#attributes']['class'][] = 'ecl-search-form';

  // Remove incompatible containers.
  unset(
    $variables['search_form']['search_input_group']['#prefix'],
    $variables['search_form']['search_input_group']['#suffix']
  );

  // Add CSS in search button.
  $variables['search_form']['europa_search_submit']['#attributes']['class'][] = 'ecl-search-form__button';

  $variables['atomium']['attributes']['element']->merge($variables['attributes']);
}
