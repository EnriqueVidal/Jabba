module Basic = {
  [@react.component]
  let make = (~message) =>
    <p className="is-size-7 has-text-danger control">
      message->React.string
    </p>;
};

module Maybe = {
  [@react.component]
  let make = (~result) =>
    switch (result) {
    | Some(Error(message)) => <Basic message />
    | _ => React.null
    };
};

include Basic;
