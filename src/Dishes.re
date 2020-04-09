[@react.component]
let make = () => {
  let (dishes, _) = DishesContext.useDishes();

  let rows =
    Belt.Map.String.valuesToArray(dishes)
    ->Belt.Array.map(({id, name, type_} as dish) =>
        <tr key=id>
          <td> name->React.string </td>
          <td> type_->Meal.toString->React.string </td>
          <td> dish->Dish.getCalories->Js.Float.toString->React.string </td>
        </tr>
      )
    |> React.array;

  <section className="section">
    <DishBreadcrumbs />
    <div className="container">
      <h1 className="title"> "Dishes"->React.string </h1>
      <h2 className="subtitle">
        "These are all the existing Dishes"->React.string
      </h2>
      <div className="table-container">
        <table
          className="table is-bordered is-fullwidth is-hoverable is-stripped">
          <thead>
            <tr>
              <th> "Dish"->React.string </th>
              <th> "Type"->React.string </th>
              <th> <abbr title="Calories"> "Cal"->React.string </abbr> </th>
            </tr>
          </thead>
          <tbody> rows </tbody>
        </table>
      </div>
    </div>
  </section>;
};
