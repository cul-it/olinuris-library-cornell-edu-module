<?php
/**
* based on https://gist.github.com/mankyKitty/5898593
*/
class views_handler_field_olinuris_field extends views_handler_field_numeric {
    
    function option_definition() {
        // It's vital you call the parent function so that the rest
        // of the handler default settings are initiated correctly.
        $options = parent::option_definition();
        // Now you can add your option with a default value.
        $options['olinuris_button_selector'] = array('default' => 'NO_CHANGE');
        // Return the $options so the handler setup can continue.
        return $options;
    }
    
    function options_form(&$form, &$form_state) {
        // Remember to call the parent::options_form if you just want to
        // add your options to the whole form instead of trying to replace
        // it entirely.
        parent::($form, $form_state);
        // Now we can add our new option using normal FAPI elements.
        $form['olinuris_button_selector'] = array(
          '#type' => 'select',
          '#title' => t('Equipment buttons'),
          '#options' => array(
            'NO_CHANGE' => t('No change'),
            'PICK_UP' => t('Pick up now'),
            'AVAILABLE' => t('Available'),
            'CHECKED_OUT' => t('Checked out'),
        ),
          // All properly defined options are saved to the handler and are accessible
          // from the 'options' array on that object. To access this use the following.
          '#default_value' => $this->options['olinuris_button_selector']
        );
        // Note that we do not return the form. We've modified it by reference so we
        // don't have to. You can also alter any component of the form here if it has
        // been added when your handler runs.
      }
    
      // The $values object contains the result of the current row.
    function render($values) {
        // Best practice is to ensure you have something to work with
        // before attempting to render anything. As Views assigns an alias
        // to every field and uses that alias to key the results you must
        // use that value to locate your data on the $values obj. Thus...
        if (!empty($values->{$this->field_alias})) {
            // You can then either just return the desired output..
            return "My Value:" . $values->{$this->field_alias}
            // You can return the result of a theme function
            return theme('my_module_field_theme', array('result_var' => $values->{$this->field_alias}));
            // Additional Fields should also be available at this point
            return "My Foo:" . $this->additional_fields['foo_prefix_var'] . $values->{$this->field_alias};
        }
    }
        
}