open Form;
open IngredientsContext;

type actions =
  | ResetForm
  | SetAmount(string)
  | SetName(string)
  | SetCalories(string);

type formState = {
  name: string,
  calories: string,
  unit: string,
};

let initialState = {name: "", calories: "0.0", unit: "Gr"};

let reducer = (state, action) =>
  switch (action) {
  | ResetForm => initialState
  | SetAmount(unit) => {...state, unit}
  | SetName(name) => {...state, name}
  | SetCalories(calories) => {...state, calories}
  };

[@react.component]
let make = (~dispatch, ~show, ~toggle) => {
  let (form, formDispatch) = React.useReducer(reducer, initialState);
  let modalClass = Cn.make(["modal", "is-active"->Cn.ifTrue(show)]);
  let amounts = toOptions(Amount.asList, Amount.toString) |> React.array;

  let onClick = evt => {
    let {name, calories, unit} = form;

    AddIngredient(name, float_of_string(calories), Amount.fromString(unit))
    |> dispatch;

    formDispatch(ResetForm);
    toggle(evt);
  };

  <div className=modalClass>
    <div className="modal-background" onClick=toggle />
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
              onChange={evt => valueFromEvent(evt)->SetName |> formDispatch}
              placeholder="e.g. Eggs"
              value={form.name}
            />
          </div>
        </div>
        <div className="field">
          <label htmlFor="units" className="label">
            "Units"->React.string
          </label>
          <div className="control">
            <div className="select">
              <select
                onChange={
                  evt => valueFromEvent(evt)->SetAmount |> formDispatch
                }
                value={form.unit}>
                amounts
              </select>
            </div>
          </div>
        </div>
        <div className="field">
          <label className="label" htmlFor="ingredientCalories">
            "Calories:"->React.string
          </label>
          <div className="control">
            <input
              className="input"
              type_="number"
              id="ingredientCalories"
              min=0
              onChange={
                evt => valueFromEvent(evt)->SetCalories |> formDispatch
              }
              step=0.1
              value={form.calories}
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
