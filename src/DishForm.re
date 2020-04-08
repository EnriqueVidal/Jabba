[@react.component]
let make = () => {
  let (ingredients, _) = IngredientsContext.useIngredients();
  let meals = Meal.(Form.toOptions(asList, toString)) |> React.array;

  let form =
    DishFormality.useForm(
      ~initialInput={
        name: "",
        recipeIngredients: [|{amount: "0", ingredient: ""}|],
        type_: "",
      },
      ~onSubmit=(_output, form) =>
      Js.Global.setTimeout(
        () => {
          form.notifyOnSuccess(None);
          form.reset();
        },
        500,
      )
      ->ignore
    );

  let fieldClass = (input, classes) =>
    Cn.make([
      Cn.mapSome(
        input,
        fun
        | Ok(_) => "is-success"
        | Error(_) => "is-danger",
      ),
      ...classes,
    ]);

  let buttonClass =
    Cn.make([
      "button",
      "is-link",
      "is-small",
      "is-loading"->Cn.ifTrue(form.submitting),
    ]);

  <section className="section">
    <div className="container">
      <h1 className="title"> "Dishes"->React.string </h1>
      <h2 className="subtitle">
        "Create dishes that will appear in your menu"->React.string
      </h2>
      <Form onSubmit={_ => form.submit()}>
        <VerticalField htmlFor="name" label="Name">
          <input
            className={fieldClass(form.nameResult, ["input", "is-small"])}
            disabled={form.submitting}
            id="name"
            onBlur={form.blurName}
            onChange={
              form.updateName((~target, input) =>
                {...input, name: target##value}
              )
            }
            placeholder="This is the name that we'll use in your menu"
            type_="text"
            value={form.input.name}
          />
          <FieldError.Maybe result={form.nameResult} />
        </VerticalField>
        <VerticalField htmlFor="meal" label="Meal">
          <div
            className={fieldClass(form.type_Result, ["select", "is-small"])}>
            <select
              disabled={form.submitting}
              id="meal"
              onBlur={form.blurType_}
              onChange={
                form.updateType_((~target, input) =>
                  {...input, type_: target##value}
                )
              }
              value={form.input.type_}>
              <option value="">
                "Pick an Item from the list"->React.string
              </option>
              meals
            </select>
          </div>
          <FieldError.Maybe result={form.type_Result} />
        </VerticalField>
        <DishNestedIngredients form ingredients />
        <div className="field is-grouped">
          <div className="control">
            <button className=buttonClass> "Save"->React.string </button>
          </div>
          <div className="control">
            <button className="button is-link is-light is-small">
              "Cancel"->React.string
            </button>
          </div>
        </div>
      </Form>
    </div>
  </section>;
};
