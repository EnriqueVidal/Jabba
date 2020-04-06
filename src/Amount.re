type t =
  | Piece
  | Slice
  | Oz
  | Gr
  | Liters;

let toString = amount =>
  switch (amount) {
  | Piece => "Piece"
  | Slice => "Slice"
  | Oz => "Oz"
  | Gr => "Gr"
  | Liters => "Liters"
  };

let fromString = amount =>
  switch (String.lowercase(amount)) {
  | "piece" => Piece
  | "slice" => Slice
  | "oz" => Oz
  | "gr" => Gr
  | "liters" => Liters
  };

let asList = [Piece, Slice, Oz, Gr, Liters];
