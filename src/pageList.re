let str = ReasonReact.string;
let array = ReasonReact.array;

let component = ReasonReact.statelessComponent("PageList");

let renderElem = f => {
  <li key=f onClick={_ => ReasonReact.Router.push("/page/" ++ f ++ ".md")}>
    {f |> str}
  </li>;
};
let renderList = list => {
  <div className=Styles.list>
    <h1> {str("List of Pages")} </h1>
    <ul>
      {list
       |> Js.Array.filter(f => f->Filename.check_suffix(".md"))
       |> Js.Array.map(f => f->Filename.chop_suffix(".md") |> renderElem)
       |> array}
    </ul>
  </div>;
};
let make = _children => {
  ...component,
  render: _self => {
    let listQuery = Queries.List.make();
    <div>
      <Queries.ListQuery variables=listQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div> {"Loading!" |> str} </div>
          | Error(error) => <div> {error##message |> str} </div>
          | Data(data) => data##list |> renderList
          }
        }
      </Queries.ListQuery>
    </div>;
  },
};