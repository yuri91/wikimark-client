let str = ReasonReact.string;

type action =
  | Home
  | PageList;

type state = {view: action};

let component = ReasonReact.reducerComponent("Main");

let make = _children => {
  ...component,
  reducer: (action, _state) => ReasonReact.Update({view: action}),
  initialState: () => {view: Home},
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | ["list"] => self.send(PageList)
        | _ => self.send(Home)
        }
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: self => {
    <div>
      {switch (self.state.view) {
       | Home => <Home />
       | PageList => <PageList />
       }}
    </div>;
  },
};