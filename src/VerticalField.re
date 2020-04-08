[@react.component]
let make = (~children, ~htmlFor="", ~label) =>
  <div className="field">
    <label htmlFor className="label"> label->React.string </label>
    <div className="control"> children </div>
  </div>;
