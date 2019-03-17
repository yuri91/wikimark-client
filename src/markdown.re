[@bs.deriving abstract]
type hljsRes = {value: string};
[@bs.module "highlight.js"]
external hljs: (string, string) => hljsRes = "highlight";

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
  | (Some(l), Some(s)) => hljs(l, s)->valueGet
  | _ => ""
  };
};
let renderer = create(markdownOptions(~highlight=hljsFn));
let render: string => string =
  md => {
    render_(renderer, md);
  };

[%bs.raw {|require('highlight.js/styles/default.css')|}];