[%bs.raw {|require('bulma')|}];

open IngredientsContext;

let addIngredient = (state, name, calories, unit_) => {
  let ingredient = Ingredient.make(name, calories, unit_);

  state->Belt.Map.String.set(ingredient.id, ingredient);
};

let reducer = (state, action) =>
  switch (action) {
  | AddIngredient(name, calories, unit_) =>
    state->addIngredient(name, calories, unit_)
  | RemoveIngredient(id) => state->Belt.Map.String.remove(id)
  | UpdateIngredient(ingredient) =>
    state->Belt.Map.String.set(ingredient.id, ingredient)
  };

let initialState = {
  let egg = Ingredient.make("Egg", 347.49, Amount.Piece);
  let ham = Ingredient.make("Pork Ham", 87.57, Amount.Slice);

  Belt.Map.String.(empty->set(egg.id, egg)->set(ham.id, ham));
};

[@react.component]
let make = () => {
  let ingredientsContext = React.useReducer(reducer, initialState);

  <IngredientsProvider value=ingredientsContext>
    <div className="container is-fluid"> <Navbar /> <Router /> </div>
    <Footer />
  </IngredientsProvider>;
};
