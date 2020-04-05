[%bs.raw {|require('bulma')|}];

open Ingredient;

[@react.component]
let make = () => {
  let ingredientsContext = React.useReducer(reducer, mock);

  <IngredientsProvider value=ingredientsContext>
    <div className="container is-fluid"> <Form /> </div>
    <footer className="footer">
      <div className="content has-text-centered">
        <strong> "Jabba"->React.string </strong>
        " is built to help us decide what to munch on"->React.string
      </div>
    </footer>
  </IngredientsProvider>;
};
