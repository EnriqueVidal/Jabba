type contextValue = (Ingredient.state, Ingredient.action => unit);

let initValue: contextValue = (Guid.Map.empty, _ => ());

let context = React.createContext(initValue);

let useIngredients = () => React.useContext(context);
