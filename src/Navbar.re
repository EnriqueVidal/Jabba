module Burger = {
  [@react.component]
  let make = (~children, ~className, ~expanded, ~onClick) =>
    ReactDOMRe.createElementVariadic(
      "a",
      ~props=
        ReactDOMRe.objToDOMProps({
          "aria-label": "menu",
          "aria-expanded": expanded,
          "className": className,
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
  let {ReasonReactRouter.path} = ReasonReactRouter.useUrl();

  React.useEffect1(
    () => {
      dispatch(_ => false);
      None;
    },
    [|path|],
  );

  let burgerClass =
    Cn.make(["navbar-burger", "burger", Cn.ifTrue("is-active", expanded)]);
  let menuClass = Cn.make(["navbar-menu", Cn.ifTrue("is-active", expanded)]);
  let onClick = _ => dispatch(_ => !expanded);

  <nav
    className="navbar is-info" role="navigation" ariaLabel="main navigation">
    <div className="navbar-brand">
      <Burger className=burgerClass expanded onClick>
        <span ariaHidden=true />
        <span ariaHidden=true />
        <span ariaHidden=true />
      </Burger>
    </div>
    <div id="navbar" className=menuClass>
      <div className="navbar-start">
        <Link className="navbar-item" href="/"> "Menu"->React.string </Link>
        <Link className="navbar-item" href="/dishes">
          "Dishes"->React.string
        </Link>
        <Link className="navbar-item" href="/ingredients">
          "Ingredients"->React.string
        </Link>
      </div>
    </div>
  </nav>;
};
