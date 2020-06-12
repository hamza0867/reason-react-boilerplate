open ReactIntl;
open I18N;

let messages =
  [@intl.messages]
  {
    "hello": {
      "id": "page.hello",
      "defaultMessage": "Hello",
    },
    "world": {
      "id": "page.world",
      "defaultMessage": "World",
    },
    "today": {
      "id": "page.today",
      "defaultMessage": "Today is",
    },
  };

[@react.component]
let make = (~locale, ~setLocale) => {
  let intl = ReactIntl.useIntl();
  let className = locale' => locale' === locale ? "active" : "";

  <div className="container">
    <div className="buttons">
      <button className={En->className} onClick={_ => En->setLocale}>
        {En->toString->React.string}
      </button>
      <button className={Fr->className} onClick={_ => Fr->setLocale}>
        {Fr->toString->React.string}
      </button>
    </div>
    <div className="message">
      <FormattedMessage
        id=messages##hello##id
        defaultMessage=messages##hello##defaultMessage
      />
      {React.string(" ")}
      <FormattedMessage
        id=messages##world##id
        defaultMessage=messages##world##defaultMessage
      />
    </div>
    <div>
      {intl->Intl.formatMessage(messages##today)->React.string}
      " "->React.string
      {intl->Intl.formatDate(Js.Date.make())->React.string}
      " (intl.formatDate)"->React.string
      <br />
      {intl->Intl.formatMessage(messages##today)->React.string}
      " "->React.string
      <FormattedDate value={Js.Date.make()} />
      " (FormattedDate)"->React.string
    </div>
    <div>
      <FormattedMessage
        id="page.html"
        defaultMessage="HTML example: <bold>bold text</bold>, <combined><italic>italic bold</italic> text</combined>"
        values={
          "bold": text => <strong> text </strong>,
          "italic": text => <em> text </em>,
          "combined": (italicBold, text) =>
            <strong> italicBold text </strong>,
        }
      />
    </div>
  </div>;
};
