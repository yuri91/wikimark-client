let component = ReasonReact.statelessComponent("App");

let str = ReasonReact.string;
let make = _children => {
  ...component,
  render: _self => {
    <div className=Styles.grid>
      <header>
        <div className="toolbar">
          <a href="/edit">
            {str("NEW ")}
            <i className=Styles.Icons.new_ />
          </a>
          <span className="toolbar-divider" />
          <span className="user">
            {str("Hi Yuri!")}
            <i className="icon-user" />
          </span>
        </div>
      </header>
      <nav>
        <div id="links">
          <h3> {str("NAVIGATION")} </h3>
          <ul>
            <li>
              <a href="/"> <i className="icon-home" /> {str("Home")} </a>
            </li>
            <li>
              <a href="/all">
                <i className="icon-all-pages" />
                {str("All Pages")}
              </a>
            </li>
          </ul>
        </div>
        <div id="toc" />
      </nav>
      <article> <PageList /> </article>
      <footer />
    </div>;
  },
};