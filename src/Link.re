[@react.component]
let make = (~children, ~className="", ~href) => {
  let onClick = event =>
    if (!event->ReactEvent.Mouse.defaultPrevented
        && event->ReactEvent.Mouse.button == 0
        && !event->ReactEvent.Mouse.altKey
        && !event->ReactEvent.Mouse.ctrlKey
        && !event->ReactEvent.Mouse.metaKey
        && !event->ReactEvent.Mouse.shiftKey) {
      event->ReactEvent.Mouse.preventDefault;
      ReasonReactRouter.push(href);
    };

  <a href className onClick> children </a>;
};
