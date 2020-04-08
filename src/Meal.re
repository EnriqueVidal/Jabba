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

let fromString = amount =>
  switch (String.lowercase_ascii(amount)) {
  | "breakfast" => Some(Breakfast)
  | "lunch" => Some(Lunch)
  | "snack" => Some(Snack)
  | "dinner" => Some(Dinner)
  | _ => None
  };

let asList = [Breakfast, Lunch, Snack, Dinner];
