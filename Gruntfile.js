/**
 * @file
 * Tasks for building the styleguide an css.
 */

'use strict';

module.exports = function (grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      sass: {
        files: ['**/*.{scss,sass}', 'sass/**/*.html'],
        tasks: ['clean', 'sass', 'shell', 'copy:main'],
        options: {
          livereload: true
        }
      }
    },

    clean: ['styleguide/assets'],
    sass: {
      options: {
        sourceMap: true
      },
      dist: {
        files: {
          'css/style-sass.css': 'sass/app.scss'
        }
      }
    },
    shell: {
      kss: {
        command: './node_modules/.bin/kss-node sass styleguide/assets --template styleguide/template/custom --css public/css/style-sass.css'
      }
    },
    copy: {
      main: {
        files: [
          // Includes files within path and its sub-directories.
          {expand: true, src: ['images/**'], dest: 'styleguide/assets/public/'},
          {expand: true, src: ['css/**'], dest: 'styleguide/assets/public/'},
        ]
      },
      all: {
        files: [
          // Includes files within path and its sub-directories.
          {expand: true, src: ['sass/**'], dest: 'styleguide/assets/public/'},
          {expand: true, src: ['bootstrap-sass/**'], dest: 'styleguide/assets/public/'},
          {expand: true, src: ['bootstrap/**'], dest: 'styleguide/assets/public/'},
          {expand: true, src: ['images/**'], dest: 'styleguide/assets/public/'},
          {expand: true, src: ['css/**'], dest: 'styleguide/assets/public/'},
        ]
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-shell');

  grunt.registerTask('default', ['watch']);
  grunt.registerTask('styleguide', ['clean', 'sass', 'shell', 'copy:main']);
  grunt.registerTask('copyall', ['copy:all']);
  grunt.registerTask('kss', ['shell']);

};
