let make = React.Context.provider(IngredientsContext.context);

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};
