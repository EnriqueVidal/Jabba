type t = {
  name: string,
  recipeIngredients: list(RecipeIngredient.t),
  instructions: list(Instruction.t),
  type_: Meal.t,
};
