[@react.component]
let make = () => {
  let onSubmit = ReactEvent.Form.preventDefault;
  let meals = Meal.(Form.toOptions(asList, toString)) |> React.array;

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
      </form>
    </div>
  </section>;
};
