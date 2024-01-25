class LocalStorage {
    static key = "tasks";
    constructor() {}
  
    static store = (key, data) => localStorage.setItem(key, JSON.stringify(data));
  
    static get = (key = LocalStorage.key) => {
      const data = localStorage.getItem(key);
      if (!data) return [];
      return JSON.parse(data);
    };
  
    static clear = (key = LocalStorage.key) => localStorage.removeItem(key);
  
    static addData = (key, newData) => {
      const data = LocalStorage.get(key);
      data.push(newData);
      LocalStorage.store(key, data);
      return data;
    };
  
    static remove = (key, id) => {
      const data = LocalStorage.get(key);
      const newData = data.filter((element) => element.id != id);
  
      LocalStorage.store(newData);
  
      return newData;
    };
  }