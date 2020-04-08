[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["dishes"] => <Dishes />
  | ["dishes", "create"] => <DishForm />
  | ["ingredients"] => <Ingredients />
  | _ => <PageNotFound />
  };
};
