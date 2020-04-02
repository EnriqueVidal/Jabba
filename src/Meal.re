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

let fromString = meal =>
  switch (String.lowercase(meal)) {
  | "breakfast" => Breakfast
  | "lunch" => Lunch
  | "snack" => Snack
  | "dinner" => Dinner
  };

let asList = [Breakfast, Lunch, Snack, Dinner];
