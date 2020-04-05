open Uuid.V4;
open IngredientsContext;

let toOptions = (options, parser) =>
  List.map(
    option => {
      let key = uuidv4();
      let value = parser(option);
      <option key value> value->React.string </option>;
    },
    options,
  )
  |> Array.of_list;

let useModal = initialState => {
  let (show, dispatch) = React.useState(_ => initialState);
  let toggle = _ => dispatch(_ => !show);

  (show, toggle);
};

[@react.component]
let make = () => {
  let (show, toggle) = useModal(false);
  let (ingredients, _) = useIngredients();

  let onSubmit = evt => ReactEvent.Form.preventDefault(evt);

  let meals = Meal.(toOptions(asList, toString)) |> React.array;
  let units = Amount.(toOptions(asList, toString)) |> React.array;
  let ingredients = Ingredient.toOptions(ingredients) |> React.array;

  <section className="section">
    <div className="container">
      <h1 className="title"> "Dishes"->React.string </h1>
      <h2 className="subtitle">
        "Create dishes that will appear in your menu"->React.string
      </h2>
      <form id="dishForm" onSubmit>
        <div className="field">
          <label htmlFor="name" className="label">
            "Name"->React.string
          </label>
          <div className="control">
            <input
              className="input"
              type_="text"
              placeholder="e.g. Ham and Eggs"
              id="name"
            />
          </div>
          <p className="help">
            "This is the name that we'll use in your menu"->React.string
          </p>
        </div>
        <div className="field">
          <label htmlFor="meals" className="label">
            "Meals"->React.string
          </label>
          <div className="control">
            <div className="select"> <select> meals </select> </div>
          </div>
        </div>
        <div className="field">
          <label htmlFor="units" className="label">
            "Units"->React.string
          </label>
          <div className="control">
            <div className="select"> <select> units </select> </div>
          </div>
        </div>
        <div className="field">
          <label htmlFor="ingredients" className="label">
            "Ingredients"->React.string
          </label>
          <div className="control">
            <div className="select"> <select> ingredients </select> </div>
          </div>
        </div>
        <div className="field">
          <div className="control">
            <button className="button is-link is-light" onClick=toggle>
              "Add Ingredient"->React.string
            </button>
          </div>
        </div>
      </form>
    </div>
    <IngredientForm show toggle />
  </section>;
};
