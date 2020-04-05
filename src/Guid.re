module Internal = {
  type t = string;
  let compare = Pervasives.compare;
};

module Map = Map.Make(Internal);
