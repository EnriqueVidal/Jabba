[@react.component]
let make = (~children, ~className="", ~href, ~onNavigate=?) => {
  let onClick = evt => {
    evt->ReactEvent.Mouse.preventDefault;
    Belt.Option.map(onNavigate, x => x()) |> ignore;
    ReasonReactRouter.push(href);
  };

  <a href className onClick> children </a>;
};
