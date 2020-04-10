let egg = Ingredient.make("Egg", 347.49, Amount.Piece);
let ham = Ingredient.make("Pork Ham", 87.57, Amount.Slice);

let ingredients =
  Belt.Map.String.(empty->set(egg.id, egg)->set(ham.id, ham));

let dishes = {
  open Belt;
  let (calories, recipeIngredients) =
    [|RecipeIngredient.make(2.0, egg), RecipeIngredient.make(2.0, ham)|]
    ->Array.reduce(
        (0.0, []),
        ((cal, rIList), {RecipeIngredient.calories} as ingredient) =>
        (cal +. calories, rIList->List.add(ingredient))
      );

  let dish =
    Dish.make("Eggs with Ham", calories, recipeIngredients, Meal.Breakfast);

  Map.String.(empty->set(dish.id, dish));
};
