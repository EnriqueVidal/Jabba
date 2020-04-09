type state = Belt.Map.String.t(Dish.t);

type action =
  | AddDish(string, list(RecipeIngredient.t), Meal.t)
  | RemoveDish(string)
  | UpdateDish(Dish.t);

type contextValue = (state, action => unit);

let initValue: contextValue = (Belt.Map.String.empty, _ => ());

let context = React.createContext(initValue);

let useDishes = () => React.useContext(context);
