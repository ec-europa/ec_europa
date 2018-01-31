/**
 * @file
 */

module.exports = {
    "id": "test",
    "viewports": [
        {
            "name": "phone",
            "width": 320,
            "height": 480
        },
        {
            "name": "tablet_v",
            "width": 568,
            "height": 1024
        },
        {
            "name": "tablet_h",
            "width": 1024,
            "height": 768
        }
    ],
    "scenarios": [
        {
            "label": "EC Europa Theme test",
            "url": "http://127.0.0.1:8888/atomium-overview",
            "referenceUrl": "http://127.0.0.1:8889/atomium-overview",
            "hideSelectors": [],
            "removeSelectors": [],
            "selectors": [
                ".banner",
                ".ecl-blockquote",
                ".ecl-button--default",
                ".ecl-button--primary",
                ".ecl-button--secondary",
                ".ecl-button--form",
                ".checkbox__input",
                ".ecl-message--success",
                ".ecl-message--informative",
                ".ecl-message--warning",
                ".ecl-message--error",
                ".ecl-message--live_stream",
                ".ecl-footer",
                ".ecl-row",
                ".ecl-label--upcoming",
                ".ecl-label--open",
                ".ecl-label--close",
                "#ec-europa-atomium-definition-form-link--3",
                ".ecl-logo",
                ".page-content",
                ".ecl-footer"
            ],
            "readyEvent": null,
            "delay": 500,
            "misMatchThreshold" : 0.1,
            "onBeforeScript": "casper/onBefore.js",
            "onReadyScript": "casper/onReady.js"
        }
    ],
    "paths": {
        "bitmaps_reference": "backstop_data/bitmaps_reference",
        "bitmaps_test": "backstop_data/bitmaps_test",
        "casper_scripts": "backstop_data/engine_scripts",
        "html_report": "backstop_data/html_report",
        "ci_report": "backstop_data/ci_report"
    },
    "casperFlags": [],
    "engine": "phantomjs",
    "report": ["CI"],
    "debug": true
}