let toOptions = (options, parser) =>
  Belt.List.toArray(options)
  ->Belt.Array.map(option => {
      let key = Uuid.V4.uuidv4();
      let value = parser(option);
      <option key value> value->React.string </option>;
    });

let valueFromEvent = evt: string => evt->ReactEvent.Form.target##value;

[@react.component]
let make = (~children, ~className="", ~onSubmit) => {
  let onSubmit' = evt => {
    if (!evt->ReactEvent.Form.defaultPrevented) {
      evt->ReactEvent.Form.preventDefault;
    };
    onSubmit();
  };

  <form className onSubmit=onSubmit'> children </form>;
};
