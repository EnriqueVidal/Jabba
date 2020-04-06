type state = Belt.Map.String.t(Ingredient.t);

type action =
  | AddIngredient(string, float)
  | RemoveIngredient(string)
  | UpdateIngredient(Ingredient.t);

type contextValue = (state, action => unit);

let initValue: contextValue = (Belt.Map.String.empty, _ => ());

let context = React.createContext(initValue);

let useIngredients = () => React.useContext(context);
