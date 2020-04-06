[%bs.raw {|require('bulma')|}];

open IngredientsContext;

let addIngredient = (state, name, calories) => {
  let ingredient = Ingredient.make(name, calories);

  state->Belt.Map.String.set(ingredient.id, ingredient);
};

let reducer = (state, action) =>
  switch (action) {
  | AddIngredient(name, calories) => state->addIngredient(name, calories)
  | RemoveIngredient(id) => state->Belt.Map.String.remove(id)
  | UpdateIngredient(ingredient) =>
    state->Belt.Map.String.set(ingredient.id, ingredient)
  };

let initialState = {
  let egg = Ingredient.make("Egg", 347.49);
  let ham = Ingredient.make("Pork Ham", 87.57);

  Belt.Map.String.(empty->set(egg.id, egg)->set(ham.id, ham));
};

[@react.component]
let make = () => {
  let ingredientsContext = React.useReducer(reducer, initialState);

  <IngredientsProvider value=ingredientsContext>
    <div className="container is-fluid"> <Form /> </div>
    <footer className="footer">
      <div className="content has-text-centered">
        <strong> "Jabba"->React.string </strong>
        " is built to help us decide what to munch on"->React.string
      </div>
    </footer>
  </IngredientsProvider>;
};
