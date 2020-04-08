module Formality = [%form
  type input = {
    name: string,
    recipeIngredients: [@field.collection] array(recipeIngredient),
    type_: string,
  }
  and recipeIngredient = {
    amount: string,
    ingredient: string,
  };
  type output = {
    name: string,
    recipeIngredients: array(recipeIngredient'),
    type_: Meal.t,
  }
  and recipeIngredient' = {
    amount: float,
    ingredient: string,
  };
  let validators = {
    name: {
      strategy: OnFirstSuccess,
      validate: input =>
        switch (input.name->String.trim->String.length) {
        | 0 => Error("Name is required")
        | _ => Ok(input.name)
        },
    },
    recipeIngredients: {
      collection: input =>
        switch (input.recipeIngredients) {
        | [||] => Error("There must be at least one ingredient")
        | _ => Ok()
        },
      fields: {
        amount: {
          strategy: OnFirstSuccess,
          validate: (input, ~at) =>
            switch (input.recipeIngredients->Belt.Array.getUnsafe(at)) {
            | {amount: ""} => Error("Amount is required")
            | {amount} =>
              switch (Belt.Float.fromString(amount)) {
              | Some(number) => Ok(number)
              | None => Error("Amount must be numeric")
              }
            },
        },
        ingredient: {
          strategy: OnFirstSuccess,
          validate: (input, ~at) =>
            switch (input.recipeIngredients->Belt.Array.getUnsafe(at)) {
            | {ingredient: ""} => Error("Ingredient is required")
            | {ingredient} => Ok(ingredient)
            },
        },
      },
    },
    type_: {
      strategy: OnFirstSuccess,
      validate: input =>
        switch (Meal.fromString(input.type_)) {
        | Some(type_) => Ok(type_)
        | None => Error("Please select a type of meal from the list")
        },
    },
  }
];

include Formality;
