let component = ReasonReact.statelessComponent("Home");

let str = ReasonReact.string;
let make = _children => {
  ...component,
  render: _self => {
    str("home");
  },
};