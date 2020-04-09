[%bs.raw {|require('bulma')|}];

let addIngredient = (state, name, calories, unit_) => {
  let ingredient = Ingredient.make(name, calories, unit_);

  state->Belt.Map.String.set(ingredient.id, ingredient);
};

let ingredientsReducer = (state, action) =>
  IngredientsContext.(
    Belt.Map.(
      switch (action) {
      | AddIngredient(name, calories, unit_) =>
        state->addIngredient(name, calories, unit_)
      | RemoveIngredient(id) => state->String.remove(id)
      | UpdateIngredient(ingredient) =>
        state->String.set(ingredient.id, ingredient)
      }
    )
  );

let ingredients = {
  let egg = Ingredient.make("Egg", 347.49, Amount.Piece);
  let ham = Ingredient.make("Pork Ham", 87.57, Amount.Slice);

  Belt.Map.String.(empty->set(egg.id, egg)->set(ham.id, ham));
};

let addDish = (state, name, meal, recipeIngredients) => {
  let dish = Dish.make(name, meal, recipeIngredients);

  state->Belt.Map.String.set(dish.id, dish);
};

let dishesReducer = (state, action) =>
  DishesContext.(
    Belt.Map.(
      switch (action) {
      | AddDish(name, meal, recipeIngredients) =>
        state->addDish(name, meal, recipeIngredients)
      | RemoveDish(id) => state->String.remove(id)
      | UpdateDish(dish) => state->String.set(dish.id, dish)
      }
    )
  );

let dishes = Belt.Map.String.empty;

[@react.component]
let make = () => {
  let ingredientsContext = React.useReducer(ingredientsReducer, ingredients);
  let dishesContext = React.useReducer(dishesReducer, dishes);

  <IngredientsProvider value=ingredientsContext>
    <DishesProvider value=dishesContext>
      <Navbar />
      <div className="container is-fluid"> <Router /> </div>
      <Footer />
    </DishesProvider>
  </IngredientsProvider>;
};
