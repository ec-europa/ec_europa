/**
 * @file
 * File component related behaviors.
 */

(function ($) {
  Drupal.behaviors.dt_file_upload = {
    attach: function (context) {
      $('input[type="file"]').each(function () {
        var $input_file = $(this),
            $parent = $input_file.parent(),
            $message = $parent.find('.file-upload__message');

        $input_file.on('change', function (event) {
          if (this.files && event.target.value) {
            // The value comes in the form of C:\something\fileName.
            var filename = event.target.value.split('\\').pop();
            // Show the selected filename in the field.
            $message.html(filename);
          }
        });
      });
    }
  };
})(jQuery);
