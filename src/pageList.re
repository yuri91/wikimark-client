let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("PageList");

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
          | Data(data) => str(data##list[0])
          }
        }
      </Queries.ListQuery>
    </div>;
  },
};