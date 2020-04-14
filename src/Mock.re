let egg = Ingredient.make("Egg", 347.49, Amount.Piece);
let ham = Ingredient.make("Pork Ham", 87.57, Amount.Slice);
let cucumber = Ingredient.make("Cucumber", 105.4, Amount.Piece);
let tajin = Ingredient.make("Tajin", 100.0, Amount.Gr);

let ingredients =
  Belt.Map.String.(
    empty
    ->set(egg.id, egg)
    ->set(ham.id, ham)
    ->set(cucumber.id, cucumber)
    ->set(tajin.id, tajin)
  );

let dishes = {
  open Belt;

  let caloriesWithIngredients = ingredients =>
    Array.reduce(
      ingredients,
      (0.0, []),
      ((cal, rIList), {RecipeIngredient.calories} as ingredient) =>
      (cal +. calories, rIList->List.add(ingredient))
    );

  let (eHCalories, eHRIngredients) =
    [|RecipeIngredient.make(2.0, egg), RecipeIngredient.make(2.0, ham)|]
    |> caloriesWithIngredients;

  let (cCalories, cRIngredients) =
    [|
      RecipeIngredient.make(1.0, cucumber),
      RecipeIngredient.make(1.0, tajin),
    |]
    |> caloriesWithIngredients;

  [
    Dish.make("Eggs with Ham", eHCalories, eHRIngredients, Meal.Breakfast),
    Dish.make("Sliced Cucumber", cCalories, cRIngredients, Meal.Snack),
  ]
  ->List.reduce(Map.String.empty, (map, {Dish.id} as dish) =>
      Map.String.set(map, id, dish)
    );
};
