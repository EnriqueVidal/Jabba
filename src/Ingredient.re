type t = {
  name: string,
  calories: float,
};

let fromList = List.map(((name, calories)) => {name, calories});

let make = (name, calories) => {name, calories};
