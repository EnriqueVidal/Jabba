[@react.component]
let make = (~children, ~htmlFor="", ~label) =>
  <div className="field is-horizontal">
    <div className="field-label is-normal">
      <label className="label is-unselectable" htmlFor>
        label->React.string
      </label>
    </div>
    <div className="field-body"> <div className="field"> children </div> </div>
  </div>;
