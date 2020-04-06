type t = {
  amount: int,
  calories: float,
  ingredient: Ingredient.t,
};

let make = (amount: int, ingredient: Ingredient.t): t => {
  amount,
  calories: float_of_int(amount) *. ingredient.calories,
  ingredient,
};
