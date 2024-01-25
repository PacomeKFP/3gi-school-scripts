const { app, BrowserWindow, Menu } = require("electron/main");
const { dialog, ipcMain, MenuItem, nativeImage } = require("electron");
const path = require("node:path");

let currentWindow;

const createBrowser = (index = "index.html") => {
  const windows = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, "preload.js"),
    },
  });

  windows.loadFile(`src/${index}`);
  currentWindow = windows;
};

const menu = new Menu();
const navigateTo = (index) => {
  if (!currentWindow) return;
  currentWindow.close();
  createBrowser(index);
};
menu.append(
  new MenuItem({
    label: "Home",
    click: () => navigateTo("index.html"),
  })
);
menu.append(
  new MenuItem({
    label: "| PPC",
    click: () => navigateTo("pierrePapierCiseau/index.html"),
  })
);

menu.append(
  new MenuItem({
    label: "| TodoList",
    click: () => navigateTo("todolist/index.html"),
  })
);

// Menu.setApplicationMenu(menu);

app.whenReady().then(createBrowser);

app.on("window-all-closed", () => {
  if (process.platform !== "darwin") {
    app.quit();
  }
});
