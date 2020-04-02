type t = {
  name: string,
  recipeIngredients: list(RecipeIngredient.t),
  instructions: list(Instruction.t),
  type_: Meal.t,
};

let egg = Ingredient.make("Egg", 347.49);
let ham = Ingredient.make("Pork Ham", 87.57);

let ingredients = [egg, ham];

let recipeIngredients =
  RecipeIngredient.[make(2, egg, Piece), make(2, ham, Slice)];

let make = () => {
  name: "Ham and Eggs",
  recipeIngredients,
  instructions:
    Instruction.fromList([
      "Fry the eggs",
      "Cook ham on the side",
      "Serve together side by side",
    ]),
  type_: Breakfast,
};
