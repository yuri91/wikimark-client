let component = ReasonReact.statelessComponent("App");

let str = ReasonReact.string;
let push = ReasonReact.Router.push;
let make = _children => {
  ...component,
  render: _self => {
    <div className=Styles.grid>
      <header>
        <div className="toolbar">
          <a onClick={_e => push("/edit")}>
            {str("NEW ")}
            <i className=Styles.Icons.new_ />
          </a>
          <span className="toolbar-divider" />
          <span className="user">
            {str("Hi Yuri!")}
            <i className=Styles.Icons.user />
          </span>
        </div>
      </header>
      <nav>
        <div id="links">
          <h3> {str("NAVIGATION")} </h3>
          <ul>
            <li>
              <a onClick={_e => push("/")}>
                <i className=Styles.Icons.home />
                {str(" Home")}
              </a>
            </li>
            <li>
              <a onClick={_e => push("/list")}>
                <i className=Styles.Icons.allPages />
                {str(" All Pages")}
              </a>
            </li>
          </ul>
        </div>
        <div id="toc" />
      </nav>
      <article className=Styles.main> <Main /> </article>
      <footer />
    </div>;
  },
};