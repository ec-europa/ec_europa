<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_table(array $form, array &$form_state) {
  $form['element1'] = array(
    '#theme' => 'table',
    '#caption' => 'Default table.',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
    ),
    '#sticky' => FALSE,
  );

  $form['element2'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with empty heading',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array('', 'header cell 1.2', 'header cell 1.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
    ),
    '#sticky' => FALSE,
  );

  $form['element3'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan #1.',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array(
        array(
          'data' => 'header cell 1.1',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.3',
          'colspan' => '3',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element4'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan #2.',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array(
        array(
          'data' => 'header cell 1.1',
          'colspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.3',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.4',
          'rowspan' => '2',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element5'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan #3.',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array(
        array(
          'data' => 'header cell 1.1',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'colspan' => '2',
        ),
        array(
          'data' => 'header cell 1.3',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.4',
          'rowspan' => '2',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element6'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan and empty heading.',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array(
        array(
          'data' => '',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.1',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'colspan' => '3',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element7'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with sticky enabled.',
    '#colgroups' => array(
      array('data' => '', 'style' => 'background-color: #fafafa;'),
      '',
      '',
    ),
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
      array('footer cell 2.1', 'footer cell 2.2', 'footer cell 2.3'),
    ),
  );

  return $form;
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_table() {
  return array(
    'label' => 'Tables',
    'description' => 'Tables.',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_table(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-table');
}
