[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["dishes", "create"] => <DishForm />
  | [] => <DishForm />
  | _ => <PageNotFound />
  };
};
