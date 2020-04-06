type t = {
  id: string,
  name: string,
  calories: float,
};

let make = (name, calories) => {id: Uuid.V1.uuidv1(), name, calories};
