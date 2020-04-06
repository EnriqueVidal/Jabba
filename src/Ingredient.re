type t = {
  id: string,
  name: string,
  calories: float,
  unit: Amount.t,
};

let make = (name, calories, unit) => {
  id: Uuid.V1.uuidv1(),
  name,
  calories,
  unit,
};
