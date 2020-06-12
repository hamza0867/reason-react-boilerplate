import ReactDOM from "react-dom";
import React from "react";
import { make as App } from "./App.bs";
import "./index.css";

if (import.meta.hot) {
  // Hot reloadable translation json files
  // modules.hot.accept does not accept dynamic dependencies,
  // have to be constants at compile-time
  import.meta.hot.acceptDeps(["./I18N.bs"], () => {
    ReactDOM.unmountComponentAtNode(MOUNT_NODE);
    ReactDOM.render(React.createElement(App, {}), MOUNT_NODE);
  });
}

const MOUNT_NODE = document.getElementById("app");
ReactDOM.render(React.createElement(App), MOUNT_NODE);
