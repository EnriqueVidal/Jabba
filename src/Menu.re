let whatAreWeHaving = time =>
  if (time < 11) {
    Meal.Breakfast;
  } else if (time < 13) {
    Meal.Snack;
  } else if (time < 18) {
    Meal.Lunch;
  } else {
    Meal.Dinner;
  };

[@react.component]
let make = () => {
  let (dishes, _) = DishesContext.useDishes();
  let (meals, setMeals) = React.useState(_ => [||]);
  let (hour, setHour) = React.useState(_ => (-1));

  React.useEffect1(
    () => {
      let updateMeals = () => {
        let currentHour =
          Js.Date.(now() |> fromFloat |> getHours |> int_of_float);

        if (currentHour == hour) {
          ();
        } else {
          let mealOfDay = whatAreWeHaving(currentHour);

          let menu =
            Belt.Map.String.valuesToArray(dishes)
            ->Belt.Array.keep(({Dish.type_}) => type_ == mealOfDay);

          setHour(_ => currentHour);
          setMeals(_ => menu);
        };
      };

      updateMeals();
      let intervalId = Js.Global.setInterval(updateMeals, 300000);

      Some(() => Js.Global.clearInterval(intervalId));
    },
    [||],
  );

  let tiles =
    Belt.Array.map(meals, ({id, name, calories}: Dish.t) =>
      <div key=id className="tile is-4 is-vertical is-child box">
        <p className="title"> name->React.string </p>
        <p> calories->Js.Float.toString->React.string </p>
      </div>
    )
    |> React.array;

  <div className="container is-fluid">
    <h1 className="title"> "Today's Menu"->React.string </h1>
    <div className="content" />
    <div className="tile is-ancestor"> tiles </div>
  </div>;
};
