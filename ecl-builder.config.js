const path = require("path");
const source_folder = __dirname + "/node_modules/@ec-europa";

module.exports = {
  scripts: [
    {
      entry: path.resolve(__dirname, "assets/scripts/entry.js"),
      dest: path.resolve(__dirname, "assets/scripts/europa.js"),
      options: {
        sourceMap: false,
        moduleName: "ECL"
      }
    }
  ],
  styles: [
    {
      entry: path.resolve(
        source_folder,
        "ecl-components-preset-base/index.scss"
      ),
      dest: path.resolve(__dirname, "assets/styles/europa.css"),
      options: {
        sourceMap: false
      }
    },
    {
      entry: path.resolve(__dirname, "assets/src/scss/editor-index.scss"),
      dest: path.resolve(__dirname, "assets/styles/wysiwyg/editor.css"),
      options: {
        sourceMap: false
      }
    }
  ],
  copy: [
    {
      from: path.resolve(source_folder, "ecl-icons/fonts"),
      to: path.resolve(__dirname, "assets/fonts")
    },
    {
      from: path.resolve(source_folder, "ecl-logos/images"),
      to: path.resolve(__dirname, "assets/images")
    },
    {
      from: path.resolve(source_folder, "ecl-social-icons/images"),
      to: path.resolve(__dirname, "assets/images")
    }
  ]
};
