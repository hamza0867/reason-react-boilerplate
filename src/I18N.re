[@bs.module "./translations/en.json"]
external en: Js.Dict.t(string) = "default";
[@bs.module "./translations/fr.json"]
external fr: Js.Dict.t(string) = "default";

type locale =
  | En
  | Fr;

let all = [|En, Fr|];

let toString =
  fun
  | En => "en"
  | Fr => "fr";

let translations =
  fun
  | En => en
  | Fr => fr;
