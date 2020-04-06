ReactDOMRe.createElementVariadic;
module Burger = {
  [@react.component]
  let make = (~children, ~className, ~expanded, ~onClick) =>
    ReactDOMRe.createElementVariadic(
      "a",
      ~props=
        ReactDOMRe.objToDOMProps({
          "aria-label": "menu",
          "aria-expanded": expanded,
          "class": className,
          "data-target": "navbar",
          "onClick": onClick,
          "role": "button",
        }),
      [|children|],
    );
};

[@react.component]
let make = () => {
  let (expanded, dispatch) = React.useState(_ => false);
  let burgerClass =
    Cn.make(["navbar-burger", "burger", Cn.ifTrue("is-active", expanded)]);
  let menuClass = Cn.make(["navbar-menu", Cn.ifTrue("is-active", expanded)]);
  let onClick = _ => dispatch(_ => !expanded);

  <nav className="navbar" role="navigation" ariaLabel="main navigation">
    <div className="navbar-brand">
      <Burger className=burgerClass expanded onClick>
        <span ariaHidden=true />
        <span ariaHidden=true />
        <span ariaHidden=true />
      </Burger>
    </div>
    <div id="navbar" className=menuClass>
      <div className="navbar-start">
        <a className="navbar-item"> "Home"->React.string </a>
        <a className="navbar-item"> "Dishes"->React.string </a>
        <a className="navbar-item"> "Ingredients"->React.string </a>
      </div>
    </div>
  </nav>;
};
