let ingredientsReducer = (state, action) =>
  IngredientsContext.(
    Belt.(
      switch (action) {
      | AddIngredient(name, calories, unit_) =>
        let ingredient = Ingredient.make(name, calories, unit_);
        Map.String.set(state, ingredient.id, ingredient);
      | RemoveIngredient(id) => Map.String.remove(state, id)
      | UpdateIngredient(ingredient) =>
        Map.String.set(state, ingredient.id, ingredient)
      }
    )
  );

let dishesReducer = (state, action) =>
  DishesContext.(
    Belt.(
      switch (action) {
      | AddDish(name, calories, recipeIngredients, meal) =>
        let dish = Dish.make(name, calories, recipeIngredients, meal);
        Map.String.set(state, dish.id, dish);
      | RemoveDish(id) => Map.String.remove(state, id)
      | UpdateDish(dish) => Map.String.set(state, dish.id, dish)
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
