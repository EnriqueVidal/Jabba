open Uuid.V4;

type t = {
  id: string,
  name: string,
  calories: float,
};

type state = Guid.Map.t(t);

type action =
  | AddIngredient(string, float)
  | RemoveIngredient(string)
  | UpdateIngredient(t);

let make = (name, calories) => {id: uuidv4(), name, calories};
let add = ingredient => Guid.Map.add(ingredient.id, ingredient);
let remove = id => Guid.Map.remove(id);

let reducer = (state, action) =>
  switch (action) {
  | AddIngredient(name, calories) => make(name, calories)->add(state)
  | RemoveIngredient(id) => state |> remove(id)
  | UpdateIngredient(ingredient) => state |> add(ingredient)
  };

let mock = {
  let egg = make("Egg", 347.49);
  let ham = make("Pork Ham", 87.57);

  Guid.Map.empty |> add(egg) |> add(ham);
};

let toOptions = ingredients =>
  ingredients
  |> Guid.Map.bindings
  |> List.map(((_, {id, name})) =>
       <option key=id value=id> name->React.string </option>
     )
  |> Array.of_list;
