/**
 * Registers the "className" Handlebars helper.
 *
 * @param {object} handlebars The global Handlebars object used by kss-node's kssHandlebarsGenerator.
 */
module.exports.register = function(handlebars) {
    handlebars.registerHelper('className', function(modifier) {
        var modifierClass = this.name,
            length = modifierClass.length,
            modifierName = modifierClass.substring(1, length);

        return new handlebars.SafeString(modifierName);
    });
};