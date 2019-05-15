[![Build Status](https://drone.fpfis.eu/api/badges/ec-europa/ec_europa/status.svg?branch=0.0.x)](https://drone.fpfis.eu/ec-europa/ec_europa) 
[![GitHub issues](https://img.shields.io/github/issues/ec-europa/ec_europa.svg)](https://github.com/ec-europa/ec_europa/issues?q=is:open+is:issue) 
[![Current Release](https://img.shields.io/github/release/ec-europa/ec_europa.svg)](https://github.com/ec-europa/ec_europa/releases)

# EC Europa Theme

Repository containing the drupal theme for the NextEuropa platform.

The EC-Europa theme is a Drupal 7 theme, implementing the styling defined for
the Digital Transformation of the European Commission.
This theme is based on a component driven design.

This theme is bundled with the version 0.21 of [ECL](https://github.com/ec-europa/europa-component-library).

Current supported browsers:

- Chrome >= 60
- Internet Explorer >= 11
- Safari >= 11
- Firefox >= 54

Table of content:
=================
- [Installation](#a-installation)
- [Styleguide](#styleguide)
- [Tests](#tests)
- [Helper tools](#helper-tools)
- [Developers notes](#developers-notes)

## Installation

Place the content of this repository into a folder in sites/all/themes and enable the theme going to admin/appearance.
The EC Europa Theme uses [Atomium](https://www.drupal.org/project/atomium) as the base theme.

## Style guide

The style guide called [Europa component library](https://ec-europa.github.io/europa-component-library)
 is to be used as a reference when building your website.

## Settings

### Option "Improved website"

On the settings page, the option 'Is this an "improved website"?' allows to
active some customization - in the home page, the switcher-page and other 
blocks.
By default, this option is checked.

## Helper tools

All the templates are provided inside the theme:

 - component templates
 - views templates
 - display suite templates

The platform provides the following modules to facilitate building your site and to integrate with Views and Fields:

#### NextEuropa Formatters (nexteuropa_formatters)

This module provides default theme implementations for custom ECL formatters.

#### NextEuropa Formatters - Views (nexteuropa_formatters_views)

This module extends nexteuropa_formatters with custom view plugins that
render content using ECL formatters.

#### NextEuropa Formatters - Fields (nexteuropa_formatters_fields)

This module extends nexteuropa_formatters with custom field formatters that
render field value using ECL formatters.

## Tests

Writing tests specific to the EC Europa Theme project is optional (at the moment). Developers that would like to use
Behat to test their work can do that by setting up a vanilla Drupal 7 site and installing the theme and its dependencies.

Tests can be ran via:

```bash
./vendor/bin/behat
```

## Developer notes

### Introduction

The theme implementation is a sub-theme of Atomium and follows its implementation logic.
For more information, please consult its [project page](https://www.drupal.org/project/atomium).

### WYSIWYG content formatter

This theme includes a particular mechanism in order to format contents that involve HTML elements; I.E.:
* "Long text" and "Text with summary" fields;
* Custom blocks containing a markup ("body").

This mechanism is based on a namespacing CSS class put on the field value container (see "ec_europa_preprocess_block()"
and "ec_europa_preprocess_field()").
This css class is "ecl-editor".

If you need to implement some specific content formats in the rich texts in your sub-theme and you want to reflect them in the WYSIWYG widget,
you just have to insert them in an "editor.css" file.<br />
This file is to be put in a repository named "wysiwyg" placed at the root of the sub-theme.

[Go to top](#table-of-content)

### Development environment

#### Usage

To start, run:

```bash
docker-compose up
```

It is advised to not daemonise `docker-compose` so it can be turned off (`CTRL+C`) quickly when it is not anymore needed.
However, there is an option to run docker on background by using the flag `-d`:

```bash
docker-compose up -d
```

Then:

```bash
docker-compose exec web composer install
docker-compose exec web ./vendor/bin/taskman drupal:site-install
```

#### Compile ECL

Requirements:

- [Node.js](https://nodejs.org/en/): `>= 6.9.5`
- [Yarn](https://yarnpkg.com/en/): `>= 0.20.3`

Setup your environment by running:

```bash
docker-compose exec -u node node npm install 
```

Build it by running:

```bash
docker-compose exec -u node node npm run build 
```

This will:

1. Compile ECL SASS to `./assets/styles/europa.css`
2. Transpile ECL JavaScript dependencies from `./assets/scripts/entry.js` to `./assets/scripts/europa.js`
3. Copy ECL fonts to `./assets/fonts/`
4. Copy ECL images to `./assets/images/`

For more details about these build steps, check [`ecl-builder` documentation](https://www.npmjs.com/package/@ec-europa/ecl-builder)

## Update ECL

Update the ECL by changing the `@ec-europa/ecl-components-preset-base` version in `package.json` and running:

```bash
npm run build
```

This will update assets such as images and fonts and re-compile CSS, resulting changes are meant to be committed to this
repository since we cannot require theme users and/or deployment procedures to build the theme locally.
