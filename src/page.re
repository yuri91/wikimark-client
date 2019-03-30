let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("Page");

let make = (~path, _children) => {
  ...component,
  render: _self => {
    let readQuery = Queries.Read.make(~path, ());
    <div>
      <Queries.ReadQuery variables=readQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div> {"Loading!" |> str} </div>
          | Error(error) => <div> {error##message |> str} </div>
          | Data(data) => <Markdown md=data##read />
          }
        }
      </Queries.ReadQuery>
    </div>;
  },
};