[@react.component]
let make = (~children, ~className="", ~href) => {
  let onClick = evt => {
    evt->ReactEvent.Mouse.preventDefault;
    ReasonReactRouter.push(href);
  };

  <a href className onClick> children </a>;
};
