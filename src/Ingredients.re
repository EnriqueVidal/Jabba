[@react.component]
let make = () => {
  let (ingredients, _) = IngredientsContext.useIngredients();

  let rows =
    Belt.Map.String.valuesToArray(ingredients)
    ->Belt.Array.map(({id, calories, name, unit}) =>
        <tr key=id>
          <td> name->React.string </td>
          <td> unit->Amount.toString->React.string </td>
          <td> calories->Js.Float.toString->React.string </td>
        </tr>
      )
    |> React.array;

  <section className="section">
    <div className="container">
      <h1 className="title"> "Ingredients"->React.string </h1>
      <h2 className="subtitle">
        "These are all the existing Ingredients"->React.string
      </h2>
      <div className="table-container">
        <table
          className="table is-bordered is-fullwidth is-hoverable is-striped">
          <thead>
            <tr>
              <th> "Ingredient"->React.string </th>
              <th> "Amount"->React.string </th>
              <th> <abbr title="Calories"> "Cal"->React.string </abbr> </th>
            </tr>
          </thead>
          <tbody> rows </tbody>
        </table>
      </div>
    </div>
  </section>;
};
