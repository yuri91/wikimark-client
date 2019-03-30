[@bs.deriving abstract]
type processResult = {
  content: string,
  meta: Js.Dict.t(string),
  toc: string,
};
[@bs.module "./markdownIt"]
external process: string => processResult = "process";

let component = ReasonReact.statelessComponent("Markdown");
let str = ReasonReact.string;

let make = (~md, _children) => {
  ...component,
  render: _self => {
    let res = process(md);
    let meta = res->metaGet;
    let content = res->contentGet;
    <div>
      <div className=Styles.title>
        <h1>
          {str(meta->Js.Dict.get("title")->Belt.Option.getWithDefault(""))}
          <a href="#" className="anchorLink">
            <span className="anchor"> {str({js| 🔗|js})} </span>
          </a>
        </h1>
      </div>
      <div
        dangerouslySetInnerHTML={"__html": content}
        className=Styles.page
      />
    </div>;
  },
};