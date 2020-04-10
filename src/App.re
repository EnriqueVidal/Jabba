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

let addDish = (state, name, calories, recipeIngredients, meal) => {
  let dish = Dish.make(name, calories, recipeIngredients, meal);
  state->Belt.Map.String.set(dish.id, dish);
};

let dishesReducer = (state, action) =>
  DishesContext.(
    Belt.Map.(
      switch (action) {
      | AddDish(name, calories, recipeIngredients, meal) =>
        state->addDish(name, calories, recipeIngredients, meal)
      | RemoveDish(id) => state->String.remove(id)
      | UpdateDish(dish) => state->String.set(dish.id, dish)
      }
    )
  );

[@react.component]
let make = () => {
  let ingredients = React.useReducer(ingredientsReducer, Mock.ingredients);
  let dishes = React.useReducer(dishesReducer, Mock.dishes);

  <IngredientsProvider value=ingredients>
    <DishesProvider value=dishes> <Router /> </DishesProvider>
  </IngredientsProvider>;
};
