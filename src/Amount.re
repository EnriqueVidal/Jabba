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

let asList = [Piece, Slice, Oz, Gr, Liters];
