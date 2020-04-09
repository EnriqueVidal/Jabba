let make = React.Context.provider(DishesContext.context);

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};
