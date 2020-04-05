type t =
  | Breakfast
  | Lunch
  | Snack
  | Dinner;

let toString = meal =>
  switch (meal) {
  | Breakfast => "Breakfast"
  | Lunch => "Lunch"
  | Snack => "Snack"
  | Dinner => "Dinner"
  };

let asList = [Breakfast, Lunch, Snack, Dinner];
