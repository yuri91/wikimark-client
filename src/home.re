let component = ReasonReact.statelessComponent("Home");

let str = ReasonReact.string;
let md = {|
  # test

  ```C
  int main() {
      return 0;
  }
  ```
|};
let make = _children => {
  ...component,
  render: _self => {
    <Markdown md />;
  },
};