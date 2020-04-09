type t = {
  id: string,
  name: string,
  recipeIngredients: list(RecipeIngredient.t),
  type_: Meal.t,
};

let getCalories = ({recipeIngredients}) =>
  recipeIngredients->Belt.List.reduce(0.0, (x, {calories}) => x +. calories);

let make = (name, recipeIngredients, type_) => {
  id: Uuid.V1.uuidv1(),
  name,
  recipeIngredients,
  type_,
};
