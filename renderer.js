const caller = () => window.preloadedAPI.ping();

document.querySelector("button#caller").addEventListener("click", () => {
  console.log("Hello World !");
  window.preloadedAPI.ping().then((response) => console.log(response));
});
