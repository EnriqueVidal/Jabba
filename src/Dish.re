type t = {
  id: string,
  name: string,
  calories: float,
  recipeIngredients: list(RecipeIngredient.t),
  type_: Meal.t,
};

let make = (name, calories, recipeIngredients, type_) => {
  id: Uuid.V1.uuidv1(),
  name,
  calories,
  recipeIngredients,
  type_,
};
