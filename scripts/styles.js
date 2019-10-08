const sass = require("node-sass");
const path = require("path");
const fs = require("fs");
const postcss = require("postcss");
const cssnano = require("cssnano");
const autoprefixer = require("autoprefixer");
const postcssNormalize = require("postcss-normalize");
const mkdirp = require("mkdirp");
const findup = require("findup-sync");

const handleError = err => {
  if (err) throw err;
};

const loadFile = (file, done) => {
  // Special behavior: embed CSS files
  if (path.extname(file) === ".css") {
    return fs.readFile(file, "utf8", (err, data) => {
      if (err) throw err;
      return done({ contents: data });
    });
  }

  return done({ file });
};

module.exports = (entry, dest, options) => {
  const plugins = [postcssNormalize(), autoprefixer()];

  let postcssSourceMap = false;
  if (options.sourceMap === true) {
    postcssSourceMap = true; // inline
  } else if (options.sourceMap === "file") {
    postcssSourceMap = { inline: false }; // as a file
  }

  if (process.env.NODE_ENV === "production") {
    plugins.push(cssnano({ safe: true }));
  }

  sass.render(
    {
      file: entry,
      outFile: dest,
      sourceMap: options.sourceMap === true,
      sourceMapContents: options.sourceMap === true,
      sourceMapEmbed: options.sourceMap === true,
      importer: (url, prev, done) => {
        try {
          const base = path.dirname(prev);
          const normalizedUrl = url.startsWith("~") ? url.substr(1) : url;
          const normalizedDir = path.dirname(normalizedUrl);
          const normalizedFile = path.basename(normalizedUrl, ".scss");
          const prefix = url.startsWith("~") ? "node_modules" : "";

          const checkFor = [
            path.join(prefix, normalizedDir, `${normalizedFile}.scss`),
            path.join(prefix, normalizedDir, `_${normalizedFile}.scss`),
            path.join(prefix, normalizedDir, `${normalizedFile}.css`),
            path.join(prefix, normalizedUrl, "index.scss"),
            path.join(prefix, normalizedDir, "package.json"),
            path.join(prefix, normalizedDir, normalizedFile, "package.json")
          ];

          const file = findup(checkFor, { cwd: base });

          if (path.basename(file) === "package.json") {
            // eslint-disable-next-line
            const pkg = require(file);
            const relativeStyle = pkg.style || pkg.main || "index.scss";
            return loadFile(
              path.resolve(path.dirname(file), relativeStyle),
              done
            );
          }

          return loadFile(file, done);
        } catch (e) {
          // Return a better error message?
          return done();
        }
      }
    },
    (sassErr, sassResult) => {
      if (sassErr) throw sassErr;

      postcss(plugins)
        .process(sassResult.css, {
          map: postcssSourceMap,
          from: entry,
          to: dest
        })
        .then(postcssResult => {
          mkdirp(path.dirname(dest), err => {
            if (err) throw err;

            fs.writeFile(dest, postcssResult.css, handleError);

            if (postcssResult.map) {
              fs.writeFile(`${dest}.map`, postcssResult.map, handleError);
            }
          });
        });
    }
  );
};
