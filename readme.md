# Funny Games

## Context
While learning How to build desktop applications with electron JS,
I challenged myself to integrate some few little games and package them into an electron app

> **Note**: I don't mean this is very smart because of the size of the build app looking the kind of games.

## Install and Package the app
- Download the code source from github using git 
 ```bash 
    git clone https://github.com/PacomeKFP/3gi-school-scripts -b funny-games
```

- Donwload and install dependencies using npm (asuming node is installed)
```bash
    npm i
```

- Configure electron-forge for your OS
```bash
    npx electron-forge import
```

- Build the project 
```bash
    npm run make
```

**Note**: If the last command fail due to something related to rpm or rmpbuild, you can open the file `./forge.config.js` and remove the maker related to npm (lookt inside the arrays with the key makers)


