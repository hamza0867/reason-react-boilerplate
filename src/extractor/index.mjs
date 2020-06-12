import fs from "fs";
import cp from "child_process";
import path from "path";
import * as Locale from "../I18N.bs.js";

const locales = Locale.all.map(Locale.toString);

const cwd = process.cwd();
const src = path.join(cwd, "src");
const bin = path.join(cwd, "node_modules", ".bin", "bs-react-intl-extractor");

console.log(`=== ⏳  Extracting messages...`);
const extracted = JSON.parse(cp.execSync(`${bin} --allow-duplicates ${src}`));
console.log(`=== ✅  Extracting messages... done.`);

for (const locale of locales) {
  console.log(`\n=== ⏳  Updating ${locale} translation...`);
  const file = path.join(src, "translations", `${locale}.json`);
  let content;
  try {
    content = JSON.parse(fs.readFileSync(file));
  } catch (error) {
    if (error.code === "ENOENT") {
      console.log(
        `=== ⚠️  Translation for ${locale} wasn't found. Creating new one.`
      );
      content = {};
    } else {
      throw error;
    }
  }

  const cache = Object.keys(content).reduce(
    (acc, key) => ({ ...acc, [key]: content[key] }),
    {}
  );
  const messages = extracted.reduce(
    (acc, msg) => ({
      ...acc,
      [msg.id]: cache[msg.id] ? cache[msg.id] : "",
    }),
    {}
  );

  fs.writeFileSync(file, JSON.stringify(messages, null, 2) + "\n");
  console.log(`=== ✅  Updating ${locale} translation... done.`);
}
