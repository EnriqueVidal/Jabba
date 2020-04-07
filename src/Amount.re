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
  switch (String.lowercase_ascii(amount)) {
  | "piece" => Some(Piece)
  | "slice" => Some(Slice)
  | "oz" => Some(Oz)
  | "gr" => Some(Gr)
  | "liters" => Some(Liters)
  | _ => None
  };

let asList = [Piece, Slice, Oz, Gr, Liters];
