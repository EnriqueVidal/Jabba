type t = {
  id: string,
  name: string,
  calories: float,
  unit_: Amount.t,
};

let make = (name, calories, unit_) => {
  id: Uuid.V1.uuidv1(),
  name,
  calories,
  unit_,
};
