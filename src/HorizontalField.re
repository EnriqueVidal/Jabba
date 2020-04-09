[@react.component]
let make = (~children, ~className="is-normal", ~htmlFor="", ~label) => {
  let labelClass = Cn.make([className, "field-label"]);
  <div className="field is-horizontal">
    <div className=labelClass>
      <label className="label is-unselectable" htmlFor>
        label->React.string
      </label>
    </div>
    <div className="field-body"> <div className="field"> children </div> </div>
  </div>;
};
