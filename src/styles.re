open Css;

let gridPos = (x1, x2, y1, y2) => {
  [
    gridColumnStart(x1),
    gridColumnEnd(x2),
    gridRowStart(y1),
    gridRowEnd(y2),
  ];
};
let headerColor = hex("086788");
let navColor = hex("263238");
let navSectionColor = hex("37474f");
let navTextColor = hex("ffffff");
let navSelectedColor = hex("4e6069");
let shadow =
  boxShadow(~x=px(0), ~y=px(0), ~blur=px(5), rgba(0, 0, 0, 0.3));
let header = [
  backgroundColor(headerColor),
  minWidth(px(0)),
  shadow,
  ...gridPos(1, 3, 1, 2),
];
let article = [minWidth(px(0)), overflow(auto), ...gridPos(2, 2, 2, 2)];
let footer = [
  backgroundColor(headerColor),
  minWidth(px(0)),
  shadow,
  ...gridPos(1, 3, 3, 4),
];
let nav = [
  selector(
    "h3",
    [
      backgroundColor(navSectionColor),
      padding(px(8)),
      margin(px(0)),
      shadow,
      textAlign(center),
    ],
  ),
  selector(
    "li",
    [
      selector(
        "a",
        [
          color(navTextColor),
          textDecoration(none),
          display(inlineBlock),
          width(pct(100.)),
          padding(px(8)),
        ],
      ),
      selector("a:hover", [backgroundColor(navSelectedColor)]),
    ],
  ),
  selector(
    "ul",
    [
      listStyleType(none),
      margin(px(0)),
      padding(px(0)),
      fontWeight(bold),
      selector("ul", [fontWeight(normal), marginLeft(px(10))]),
    ],
  ),
  backgroundColor(navColor),
  minWidth(px(0)),
  ...gridPos(1, 2, 2, 3),
];

let toolbar = [
  display(flexBox),
  flexDirection(row),
  justifyContent(flexEnd),
  margin(px(12)),
  fontWeight(bold),
  selector(
    "a, .user",
    [
      textDecoration(none),
      color(navTextColor),
      paddingRight(px(12)),
      paddingTop(px(4)),
    ],
  ),
  selector(
    ".toolbar-divider",
    [
      borderLeft(px(3), solid, white),
      height(px(24)),
      marginTop(px(4)),
      marginRight(px(8)),
    ],
  ),
];

let grid =
  Css.style([
    display(grid),
    gridTemplateColumns([px(200), auto]),
    gridTemplateRows([px(60), auto, px(60)]),
    selector("header", header),
    selector("article", article),
    selector("footer", footer),
    selector("nav", nav),
    selector(".toolbar", toolbar),
    selector("*", [boxSizing(borderBox)]),
    height(pct(100.)),
    fontSize(pct(62.5)),
    fontFamily("'Helvetica Neue', Helvetica, Arial, sansSerif"),
    fontSize(px(14)),
  ]);

Css.global("body, html", [height(pct(100.))]);

module Icons = {
  [@bs.module] external newSvg: string = "./icons/new.svg";
  [@bs.module] external editSvg: string = "./icons/edit.svg";
  [@bs.module] external homeSvg: string = "./icons/home.svg";
  [@bs.module] external allPagesSvg: string = "./icons/all-pages.svg";

  let common = [
    display(inlineBlock),
    width(px(24)),
    height(px(24)),
    backgroundSize(size(px(24), px(24))),
    verticalAlign(middle),
  ];
  let new_ = Css.style([background(url(newSvg)), ...common]);
  let edit = Css.style([background(url(editSvg)), ...common]);
  let home = Css.style([background(url(homeSvg)), ...common]);
  let allPages = Css.style([background(url(allPagesSvg)), ...common]);

  let user =
    Css.style([
      display(inlineBlock),
      height(px(24)),
      verticalAlign(middle),
    ]);
};