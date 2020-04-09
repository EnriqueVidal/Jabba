module RemoveButton = {
  [@react.component]
  let make = (~form: DishFormality.interface('a), ~index) =>
    if (index < 1) {
      React.null;
    } else {
      <div className="control">
        <button
          className="button is-danger is-small"
          disabled={form.submitting}
          onClick={_ => form.removeRecipeIngredient(~at=index)}>
          "Remove"->React.string
        </button>
      </div>;
    };
};

module NestedLabel = {
  [@react.component]
  let make = (~children, ~index) =>
    if (index < 1) {
      <div className="field">
        <label className="label"> children </label>
      </div>;
    } else {
      React.null;
    };
};

[@react.component]
let make = (~form: DishFormality.interface('a), ~ingredients) => {
  let options =
    Belt.Map.String.valuesToArray(ingredients)
    ->Belt.Array.map(({id, name}: Ingredient.t) =>
        <option key=id value=id> name->React.string </option>
      )
    |> React.array;

  let displayAmount = ingredient =>
    switch ("Amount", ingredient) {
    | (default, "") => default
    | (default, id) =>
      Belt.Map.String.get(ingredients, id)
      ->Belt.Option.mapWithDefault(default, ({Ingredient.unit_}) =>
          unit_->Amount.toString
        )
    };

  let update = (target, input: DishFormality.input, index, key) => {
    ...input,
    recipeIngredients:
      input.recipeIngredients
      ->Belt.Array.mapWithIndex((idx, ri) =>
          switch (idx == index, key) {
          | (true, "amount") => {...ri, amount: target##value}
          | (true, "ingredient") => {...ri, ingredient: target##value}
          | _ => ri
          }
        ),
  };

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

  form.input.recipeIngredients
  ->Belt.Array.mapWithIndex((index, rIngredient) =>
      <div
        key={"recipeIngredient" ++ index->string_of_int}
        className="field is-grouped">
        <div className="control">
          <NestedLabel index> "Ingredient"->React.string </NestedLabel>
          <div
            className={
              fieldClass(
                form.recipeIngredientIngredientResult(~at=index),
                "select",
              )
            }>
            <select
              onBlur={form.blurRecipeIngredientIngredient(~at=index)}
              onChange={
                form.updateRecipeIngredientIngredient(
                  ~at=index, (~target, input) =>
                  update(target, input, index, "ingredient")
                )
              }
              value={rIngredient.ingredient}>
              <option value=""> "Pick an Ingredient"->React.string </option>
              options
            </select>
          </div>
        </div>
        <div className="control">
          <NestedLabel index> "Amount"->React.string </NestedLabel>
          <div className="field has-addons">
            <span className="control">
              <input
                className={
                  fieldClass(
                    form.recipeIngredientAmountResult(~at=index),
                    "input",
                  )
                }
                disabled={form.submitting}
                onBlur={form.blurRecipeIngredientAmount(~at=index)}
                onChange={
                  form.updateRecipeIngredientAmount(
                    ~at=index, (~target, input) =>
                    update(target, input, index, "amount")
                  )
                }
                placeholder="Amount needed for dish"
                value={rIngredient.amount}
                type_="text"
              />
            </span>
            <span className="control">
              <span
                className={
                  fieldClass(
                    form.recipeIngredientAmountResult(~at=index),
                    "button",
                  )
                }>
                rIngredient.ingredient->displayAmount->React.string
              </span>
            </span>
          </div>
        </div>
        <RemoveButton form index />
      </div>
    )
  ->React.array;
};
