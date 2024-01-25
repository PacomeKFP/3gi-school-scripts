const addBtn = document.querySelector("button#add-task");
const titleInput = document.getElementById("task-label");
const taskListDiv = document.querySelector("div#task-list");

const tasks = [];

const newTask = ({ id, title, done }) => {
  return `
    <div class="task-line">
        <div class="task">
            <span id="task-title-${id}" class="task-title"> ${title}</span>
        </div>
        ${
          !done
            ? `<button class="mark-as-done-btn" id="done-${id}">Faire</button>`
            : "✅"
        }
        
    </div>`;
};

window.addEventListener("DOMContentLoaded", () => {
  console.log("Loading Tasks");
  tasks.push(...LocalStorage.get("tasks"));
  tasks.forEach((task) => {
    console.log(`Task ${task.id}`, task);
    taskListDiv.innerHTML += newTask(task);
    document
      .getElementById(`done-${task.id}`)
      .addEventListener("click", () => markAsDone(task.id));
  });
});

const addTask = () => {
  if (!titleInput.value)
    return alert("Veuillez entrer un titre pour la nouvelle tache");
  const task = { done: false };
  task.title = titleInput.value;
  do {
    task.id = Math.round(Math.random() * 10000);
  } while (
    tasks.length != 0 &&
    tasks.filter((el) => el.id == task.id).length != 0
  );

  tasks.push(task);
  // update the UI
  titleInput.value = "";
  taskListDiv.innerHTML += newTask(task);

  // add the mark as done event listeners
  document
    .getElementById(`done-${task.id}`)
    .addEventListener("click", () => markAsDone(task.id));

  LocalStorage.addData("tasks", task);
};

const markAsDone = (id) => {
  const task = tasks.find((task) => task.id == id && !task.done);

  if (!task) return;
  task.done = true;

  taskListDiv.innerHTML = "";

  tasks.forEach((task) => (taskListDiv.innerHTML += newTask(task)));
  LocalStorage.store(tasks);
};

addBtn.addEventListener("click", addTask);
