type t = {
  amount: int,
  calories: float,
  ingredient: Ingredient.t,
  unit: Amount.t,
};

let make = (amount: int, ingredient: Ingredient.t, unit: Amount.t): t => {
  amount,
  calories: float_of_int(amount) *. ingredient.calories,
  ingredient,
  unit,
};
