[@react.component]
let make = (~form: DishFormality.interface('a), ~ingredients) => {
  let options =
    Belt.Map.String.valuesToArray(ingredients)
    ->Belt.Array.map(({Ingredient.id, Ingredient.name}) =>
        <option key=id value=id> name->React.string </option>
      )
    |> React.array;

  let displayAmount = ingredient =>
    switch (ingredient) {
    | "" => "Amount"->React.string
    | id =>
      let {Ingredient.unit_} = Belt.Map.String.getExn(ingredients, id);
      unit_->Amount.toString->React.string;
    };

  let update = (target, input: DishFormality.input, index, key) => {
    ...input,
    recipeIngredients:
      input.recipeIngredients
      ->Belt.Array.mapWithIndex((idx, ri) =>
          if (index != idx) {
            ri;
          } else {
            switch (key) {
            | "amount" => {...ri, amount: target##value}
            | "ingredient" => {...ri, ingredient: target##value}
            | _ => ri
            };
          }
        ),
  };

  let fields =
    form.input.recipeIngredients
    ->Belt.Array.mapWithIndex((index, rIngredient) =>
        <div
          key={"recipeIngredient" ++ index->string_of_int}
          className="field is-grouped">
          <div className="control">
            <div className="field has-addons">
              <span className="control">
                <input
                  className="input is-small"
                  disabled={form.submitting}
                  onBlur={form.blurRecipeIngredientAmount(~at=index)}
                  onChange={
                    form.updateRecipeIngredientAmount(
                      ~at=index, (~target, input) =>
                      update(target, input, index, "amount")
                    )
                  }
                  value={rIngredient.amount}
                  type_="number"
                />
              </span>
              <span className="control">
                <a className="button is-static is-small">
                  {displayAmount(rIngredient.ingredient)}
                </a>
              </span>
            </div>
          </div>
          <div className="control">
            <div className="select is-small">
              <select
                onBlur={form.blurRecipeIngredientIngredient(~at=index)}
                onChange={
                  form.updateRecipeIngredientIngredient(
                    ~at=index, (~target, input) =>
                    update(target, input, index, "ingredient")
                  )
                }
                value={rIngredient.ingredient}>
                <option value="">
                  "Pick an Ingredient from the list"->React.string
                </option>
                options
              </select>
            </div>
          </div>
          {
            if (index > 0) {
              <div className="control">
                <button
                  className="button is-danger is-small"
                  disabled={form.submitting}
                  onClick={_ => form.removeRecipeIngredient(~at=index)}>
                  "Remove Ingredient"->React.string
                </button>
              </div>;
            } else {
              React.null;
            }
          }
        </div>
      )
    ->React.array;

  <>
    fields
    <div className="field is-grouped">
      <button
        className="button is-primary is-small"
        onClick={
          evt => {
            evt->ReactEvent.Mouse.preventDefault;
            form.addRecipeIngredient({amount: "0", ingredient: ""});
          }
        }>
        "Add Ingredient"->React.string
      </button>
    </div>
  </>;
};
