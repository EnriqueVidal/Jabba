[@react.component]
let make = () => {
  let (dishes, dispatch) = DishesContext.useDishes();

  let rows =
    Belt.Map.String.valuesToArray(dishes)
    ->Belt.Array.map(({id, calories, name, type_}) =>
        <tr key=id>
          <td> name->React.string </td>
          <td> type_->Meal.toString->React.string </td>
          <td> calories->Js.Float.toString->React.string </td>
          <td>
            <button
              className="button is-danger"
              onClick={_ => dispatch(DishesContext.RemoveDish(id))}>
              "Remove"->React.string
            </button>
          </td>
        </tr>
      )
    |> React.array;

  <div className="container is-fluid">
    <DishBreadcrumbs />
    <h1 className="title"> "Dishes"->React.string </h1>
    <div className="content">
      <p> "These are all the existing Dishes"->React.string </p>
      <div className="table-container">
        <table className="table is-fullwidth is-hoverable is-stripped">
          <thead>
            <tr>
              <th> "Dish"->React.string </th>
              <th> "Type"->React.string </th>
              <th> <abbr title="Calories"> "Cal"->React.string </abbr> </th>
              <th> "Actions"->React.string </th>
            </tr>
          </thead>
          <tbody> rows </tbody>
        </table>
      </div>
    </div>
  </div>;
};
