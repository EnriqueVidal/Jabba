type t = {
  order: int,
  text: string,
};

let fromList = list =>
  List.rev(list) |> List.mapi((order, text) => {order, text});

let add = (text, ~instructions=[], ()) => {
  let order = List.length(instructions);
  let instruction = {order, text};

  [instruction, ...instructions];
};
