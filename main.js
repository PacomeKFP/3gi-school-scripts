const { dialog } = require("electron");
const { app, BrowserWindow, Menu } = require("electron/main");
const path = require("node:path");

let windows;

const createBrowser = () => {
  const windows = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, "preload.js"),
    },
  });

  windows.loadFile("index.html");

  return windows;
};

app.whenReady().then(() => {
  windows = createBrowser();
});


const handler = (event) => {
    event.preventDefault();
    const response = dialog.showMessageBox({
        type: "question",
        buttons: ["Yes", "No"],
        message: "Do you want to exit?",
    });
    if (response) app.quit();
};

app.on("window-all-closed",handler);
app.on("before-quit", handler);
app.on('quit', handler);

app.on("activate", () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    createBrowser();
  }
});
