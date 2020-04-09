let useModal = (~initialState=false, ()) => {
  let (state, dispatch) = React.useState(_ => initialState);
  let toggle = () => dispatch(_ => !state);

  (state, toggle);
};

let buildRecipe = (ingredients, recipeIngredients) =>
  Belt.(
    recipeIngredients
    ->Array.map(({amount, ingredient}: DishFormality.recipeIngredient') =>
        ingredients->Map.String.getExn(ingredient)
        |> RecipeIngredient.make(amount)
      )
    ->List.fromArray
  );

[@react.component]
let make = () => {
  let (show, toggle) = useModal();
  let (ingredients, iDispatch) = IngredientsContext.useIngredients();
  let (_, dDispatch) = DishesContext.useDishes();

  let meals = Meal.(Form.toOptions(asList, toString)) |> React.array;

  let form =
    DishFormality.useForm(
      ~initialInput={
        name: "",
        recipeIngredients: [|{amount: "", ingredient: ""}|],
        type_: "",
      },
      ~onSubmit=(output, form) => {
        let {name, type_, recipeIngredients}: DishFormality.output = output;

        DishesContext.AddDish(
          name,
          buildRecipe(ingredients, recipeIngredients),
          type_,
        )
        ->dDispatch;

        Js.Global.setTimeout(
          () => {
            form.notifyOnSuccess(None);
            ReasonReactRouter.push("/dishes");
          },
          500,
        )
        ->ignore;
      },
    );

  let fieldClass = (input, fClass) =>
    Cn.make([
      fClass,
      "is-small",
      Cn.mapSome(
        input,
        fun
        | Ok(_) => "is-success"
        | Error(_) => "is-danger",
      ),
    ]);

  let buttonClass =
    Cn.make([
      "button",
      "is-link",
      "is-small",
      "is-loading"->Cn.ifTrue(form.submitting),
    ]);

  <section className="section">
    <DishBreadcrumbs />
    <div className="container">
      <h1 className="title"> "Dishes"->React.string </h1>
      <h2 className="subtitle">
        "Create dishes that will appear in your menu"->React.string
      </h2>
      <Form onSubmit={_ => form.submit()}>
        <VerticalField htmlFor="dishName" label="Name">
          <input
            className={fieldClass(form.nameResult, "input")}
            disabled={form.submitting}
            id="dishName"
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
        <VerticalField htmlFor="dishMeal" label="Meal">
          <div className={fieldClass(form.type_Result, "select")}>
            <select
              disabled={form.submitting}
              id="dishMeal"
              onBlur={form.blurType_}
              onChange={
                form.updateType_((~target, input) =>
                  {...input, type_: target##value}
                )
              }
              value={form.input.type_}>
              <option value=""> "Pick a Meal"->React.string </option>
              meals
            </select>
          </div>
          <FieldError.Maybe result={form.type_Result} />
        </VerticalField>
        <DishNestedIngredients form ingredients />
        <div className="field is-grouped">
          <div className="control">
            <button
              className="button is-success is-small"
              onClick={
                evt => {
                  evt->ReactEvent.Mouse.preventDefault;
                  form.addRecipeIngredient({amount: "", ingredient: ""});
                }
              }>
              "Add Ingredient to Dish"->React.string
            </button>
          </div>
          <div className="control">
            <button
              className=buttonClass
              onClick={
                evt => {
                  evt->ReactEvent.Mouse.preventDefault;
                  toggle();
                }
              }>
              "Add Ingredient to List"->React.string
            </button>
          </div>
        </div>
        <div className="field is-grouped">
          <div className="control">
            <button className=buttonClass> "Save"->React.string </button>
          </div>
          <div className="control">
            <Link className="button is-link is-light is-small" href="/dishes">
              "Cancel"->React.string
            </Link>
          </div>
        </div>
      </Form>
    </div>
    <IngredientForm dispatch=iDispatch show toggle />
  </section>;
};
