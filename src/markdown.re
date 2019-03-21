[@bs.deriving abstract]
type hljsRes = {value: string};
[@bs.module "highlight.js"]
external hljs: (string, string) => hljsRes = "highlight";
[@bs.module "highlight.js"]
external hljsAuto: string => hljsRes = "highlightAuto";

[@bs.deriving abstract]
type markdownOptions = {
  highlight: (option(string), option(string)) => string,
};

type markdown;
[@bs.new] [@bs.module]
external create: markdownOptions => markdown = "markdown-it";

[@bs.send] external render_: (markdown, string) => string = "render";

let hljsFn = (so: option(string), lo: option(string)) => {
  switch (lo, so) {
  | (Some(""), Some(s)) => hljsAuto(s)->valueGet
  | (Some(l), Some(s)) => hljs(l, s)->valueGet
  | _ => ""
  };
};
let renderer = create(markdownOptions(~highlight=hljsFn));
let render: string => string =
  md => {
    render_(renderer, md);
  };

[%bs.raw {|require('highlight.js/styles/solarized-dark.css')|}];

let component = ReasonReact.statelessComponent("Markdown");

let make = (~md, _children) => {
  ...component,
  render: _self => {
    <div
      dangerouslySetInnerHTML={"__html": render(md)}
      className=Styles.page
    />;
  },
};