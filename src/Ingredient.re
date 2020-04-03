open Uuid.V4;

type t = {
  id: string,
  name: string,
  calories: float,
};

let toOptions = (ingredients: list(t)) =>
  List.map(
    ingredient => {
      let {id, name} = ingredient;
      <option key=id value=id> name->React.string </option>;
    },
    ingredients,
  )
  |> Array.of_list;

let make = (name, calories) => {id: uuidv4(), name, calories};
