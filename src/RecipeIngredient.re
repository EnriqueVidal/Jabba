type t = {
  amount: float,
  calories: float,
  ingredient: Ingredient.t,
};

let make = (amount, ingredient: Ingredient.t): t => {
  amount,
  calories: amount *. ingredient.calories,
  ingredient,
};
