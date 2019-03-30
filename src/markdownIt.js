var mdIt = require("markdown-it");
var meta = require("markdown-it-meta");
var tocAndAnchor = require("markdown-it-toc-and-anchor").default;
var hljs = require("highlight.js");

require("highlight.js/styles/solarized-dark.css");

var md = mdIt({
    highlight: function (str, lang) {
        if (lang && hljs.getLanguage(lang)) {
            try {
                return hljs.highlight(lang, str, true).value;
            } catch (__) { }
        }
        return ''; // use external default escaping
    }
});

md.use(meta);
md.use(tocAndAnchor, {
    toc: false,
    tocCallback: (_tocMd, _tocArr, tocHtml) => {
        md.toc = tocHtml;
    },
    anchorLink: true,
    anchorLinkSymbol: "🔗",
    anchorLinkSpace: true,
    anchorLinkSymbolClassName: "anchor",
    anchorClassName: "anchorLink",
    anchorLinkBefore: false,
});

const process = (source) => {
    let content = md.render(source);
    let meta = md.meta;
    let toc = md.toc;
    return {
        content,
        meta,
        toc,
    };
};

exports.process = process;