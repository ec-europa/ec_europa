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
            "url": "http://localhost:8888/atomium-overview",
            "referenceUrl": "http://localhost:8889/atomium-overview",
            "hideSelectors": [],
            "removeSelectors": [],
            "selectors": [
                ".ecl-page-header",
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