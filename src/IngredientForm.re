let valueFromEvent = evt: string => evt->ReactEvent.Form.target##value;

type actions =
  | ResetForm
  | SetName(string)
  | SetCalories(string);

let initialState = Ingredient.make("", 0.0);

let reducer = (state: Ingredient.t, action: actions): Ingredient.t =>
  switch (action) {
  | ResetForm => initialState
  | SetName(name) => {...state, name}
  | SetCalories(calories) => {...state, calories: float_of_string(calories)}
  };

let useIngredients = IngredientsContext.useIngredients;

[@react.component]
let make = (~show, ~toggle) => {
  let (ingredient, dispatch) = React.useReducer(reducer, initialState);
  let (_, dispatchIngredient) = useIngredients();

  let modalClass = Cn.make(["modal", "is-active"->Cn.ifTrue(show)]);

  let onClick = evt => {
    dispatchIngredient(IngredientsContext.AddIngredient(ingredient));
    dispatch(ResetForm);
  };

  <div className=modalClass id="ingredientModal">
    <div className="modal-background" />
    <div className="modal-card">
      <header className="modal-card-head">
        <p className="modal-card-title"> "Create Ingredient"->React.string </p>
      </header>
      <section className="modal-card-body">
        <div className="field">
          <label className="label" htmlFor="ingredientName">
            "Name:"->React.string
          </label>
          <div className="control">
            <input
              className="input"
              type_="text"
              id="ingredientName"
              onChange={evt => valueFromEvent(evt)->SetName |> dispatch}
              placeholder="e.g. Eggs"
            />
          </div>
        </div>
        <div className="field">
          <label className="label" htmlFor="ingredientCalories">
            "Calories:"->React.string
          </label>
          <div className="control">
            <input
              className="input"
              defaultValue="0.0"
              type_="number"
              id="ingredientCalories"
              min=0
              onChange={evt => valueFromEvent(evt)->SetCalories |> dispatch}
              step=0.01
            />
          </div>
        </div>
      </section>
      <footer className="modal-card-foot">
        <button className="button is-success" onClick>
          "Create Ingredient"->React.string
        </button>
        <button className="button" onClick=toggle>
          "Cancel"->React.string
        </button>
      </footer>
    </div>
  </div>;
};
