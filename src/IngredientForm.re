open IngredientsContext;

module Formality = [%form
  type input = {
    name: string,
    calories: string,
    unit_: string,
  };
  type output = {
    name: string,
    calories: float,
    unit_: Amount.t,
  };
  let validators = {
    name: {
      strategy: OnFirstSuccessOrFirstBlur,
      validate: input =>
        switch (input.name->String.trim->String.length) {
        | 0 => Error("Name is required")
        | _ => Ok(input.name)
        },
    },
    calories: {
      strategy: OnFirstSuccessOrFirstBlur,
      validate: input =>
        switch (Belt.Float.fromString(input.calories)) {
        | Some(calories) => Ok(calories)
        | None => Error("Calories must be numeric")
        },
    },
    unit_: {
      strategy: OnFirstBlur,
      validate: input =>
        switch (Amount.fromString(input.unit_)) {
        | Some(unit_) => Ok(unit_)
        | None => Error("Please select a Unit from the list")
        },
    },
  }
];

[@react.component]
let make = (~dispatch, ~show, ~toggle) => {
  let amounts = Form.toOptions(Amount.asList, Amount.toString) |> React.array;

  let form =
    Formality.useForm(
      ~initialInput={name: "", calories: "", unit_: ""},
      ~onSubmit=(output, form) => {
        let {name, calories, unit_}: Formality.output = output;

        AddIngredient(name, calories, unit_) |> dispatch;

        toggle();
        form.notifyOnSuccess(None);
        form.reset();
      },
    );

  let cancel = evt => {
    evt->ReactEvent.Mouse.preventDefault;
    toggle();
    form.reset();
  };

  let modalClass = Cn.make(["modal", "is-active"->Cn.ifTrue(show)]);

  let fieldClass = (input, ~defaultC="input", ()) =>
    Cn.make([
      defaultC,
      Cn.mapSome(
        input,
        fun
        | Ok(_) => "is-success"
        | Error(_) => "is-danger",
      ),
    ]);

  let buttonClass =
    Cn.make(["button", "is-link", "is-loading"->Cn.ifTrue(form.submitting)]);

  <div className=modalClass>
    <div className="modal-background" onClick=cancel />
    <Form onSubmit={_ => form.submit()}>
      <div className="modal-card">
        <header className="modal-card-head">
          <p className="modal-card-title is-unselectable">
            "Create Ingredient"->React.string
          </p>
        </header>
        <section className="modal-card-body">
          <HorizontalField htmlFor="ingredientName" label="Name:">
            <input
              className={fieldClass(form.nameResult, ())}
              disabled={form.submitting}
              type_="text"
              id="ingredientName"
              placeholder="e.g. Eggs"
              onBlur={form.blurName}
              onChange={
                form.updateName((~target, input) =>
                  {...input, name: target##value}
                )
              }
              value={form.input.name}
            />
            <FieldError.Maybe result={form.nameResult} />
          </HorizontalField>
          <HorizontalField htmlFor="ingredientUnit" label="Unit:">
            <div
              className={fieldClass(form.unit_Result, ~defaultC="select", ())}>
              <select
                disabled={form.submitting}
                id="ingredientUnit"
                onBlur={form.blurUnit_}
                onChange={
                  form.updateUnit_((~target, input) =>
                    {...input, unit_: target##value}
                  )
                }
                value={form.input.unit_}>
                <option value="">
                  "Please select an option"->React.string
                </option>
                amounts
              </select>
            </div>
            <FieldError.Maybe result={form.unit_Result} />
          </HorizontalField>
          <HorizontalField htmlFor="ingredientCalories" label="Calories:">
            <input
              className={fieldClass(form.caloriesResult, ())}
              disabled={form.submitting}
              id="ingredientCalories"
              min=0
              step=0.1
              onBlur={form.blurCalories}
              onChange={
                form.updateCalories((~target, input) =>
                  {...input, calories: target##value}
                )
              }
              placeholder="Calories per Unit"
              value={form.input.calories}
            />
            <FieldError.Maybe result={form.caloriesResult} />
          </HorizontalField>
        </section>
        <footer className="modal-card-foot">
          <button className=buttonClass disabled={form.submitting}>
            "Save"->React.string
          </button>
          <button className="button" onClick=cancel>
            "Cancel"->React.string
          </button>
        </footer>
      </div>
    </Form>
  </div>;
};
