let str = ReasonReact.string;

type action =
  | Home
  | PageList
  | Page(string);

type state = {view: action};

let component = ReasonReact.reducerComponent("Main");

let route = path => {
  switch (path) {
  | ["list"] => PageList
  | ["page", path] => Page(path)
  | _ => Home
  };
};
let make = _children => {
  ...component,
  reducer: (action, _state) => ReasonReact.Update({view: action}),
  initialState: () => {
    view: route(ReasonReact.Router.dangerouslyGetInitialUrl().path),
  },
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url => self.send(route(url.path)));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: self => {
    <div>
      {switch (self.state.view) {
       | Home => <Home />
       | PageList => <PageList />
       | Page(path) => <Page path />
       }}
    </div>;
  },
};