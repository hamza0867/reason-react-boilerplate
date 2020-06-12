open I18N;
type action =
  | SetLocale(locale);

let initialState = En;

let reducer = (_, action) =>
  switch (action) {
  | SetLocale(locale) => locale
  };

[@react.component]
let make = () => {
  let (locale, dispatch) = reducer->React.useReducer(initialState);

  <ReactIntl.IntlProvider
    locale={locale->toString} messages={locale->translations}>
    <Page locale setLocale={locale => locale->SetLocale->dispatch} />
  </ReactIntl.IntlProvider>;
};
