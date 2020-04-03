type state = list(Ingredient.t);
type action =
  | FetchIngredients
  | AddIngredient(string, float);

type dispatch = action => unit;
type contextValue = (state, dispatch);

let reducer = (state, action) =>
  switch (action) {
  | FetchIngredients => Dish.ingredients
  | AddIngredient(name, calories) => [
      Ingredient.make(name, calories),
      ...state,
    ]
  };

let initValue: contextValue = ([], _ => ignore());

let context = React.createContext(initValue);

let useIngredients = () => React.useContext(context);
