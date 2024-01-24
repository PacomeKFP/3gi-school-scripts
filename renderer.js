const contenantChoixUtilisateur = document.getElementById("choix-utilisateur");
const contenantChoixOrdinateur = document.getElementById("choix-ordinateur");
const contenantResultat = document.getElementById("resultat");

const choixPossibles = document.querySelectorAll("button");

let choixUtilisateur;
let resultat;
let choixOrdinateur;



// Evenement 'Click' sur le boutton
choixPossibles.forEach((choixPossible) =>
  choixPossible.addEventListener("click", (e) => {

    //récupération de l'ID du boutton cliqué
    choixUtilisateur = e.target.id;
    //On ajoute l'image qui correspond au choix
    contenantChoixUtilisateur.innerHTML =
      "<img src =" + choixUtilisateur + ".png>";

    generer_choix_ordinateur();

    verification();
  })
);

//Fonction pour générer le choix de l'ordinateur
function generer_choix_ordinateur() {
  random = Math.floor(Math.random() * 3) + 1; //Générer des nombres compris entre 1 et 3
  if (random == 1) {
    // si random = 1
    choixOrdinateur = "pierre";
  }
  if (random == 2) {
    // si random = 2
    choixOrdinateur = "papier";
  }
  if (random == 3) {
    // si random = 3
    choixOrdinateur = "ciseaux";
  }


  //On ajoute l'image qui correspond au choix
  contenantChoixOrdinateur.innerHTML = "<img src =" + choixOrdinateur + ".png>";
}

//Fonction pour vérifier si le joueur a gagné ou pas
function verification() {
  if (choixUtilisateur == choixOrdinateur) {
    resultat = "Egalité !";
  }
  //Les cas où le joueur perd
  if (choixUtilisateur == "pierre" && choixOrdinateur == "papier") {
    resultat = "Perdu !";
  }
  if (choixUtilisateur == "papier" && choixOrdinateur == "ciseaux") {
    resultat = "Perdu !";
  }
  if (choixUtilisateur == "ciseaux" && choixOrdinateur == "pierre") {
    resultat = "Perdu !";
  }
  // Les cas où le joeur gagne
  if (choixUtilisateur == "pierre" && choixOrdinateur == "ciseaux") {
    resultat = "Gagné !";
  }
  if (choixUtilisateur == "ciseau" && choixOrdinateur == "papier") {
    resultat = "Gagné !";
  }
  if (choixUtilisateur == "papier" && choixOrdinateur == "pierre") {
    resultat = "Gagné !";
  }
  contenantResultat.innerHTML = resultat;
}
/*
  //Mon comment lire
  console.log("Hello World");
  console.log(4/8);
 const myvar = 10;
  console.log(myvar);

  console.log(typeof(myvar));
  const user = {
    name: "hassan",
    age: "42",
  };
  console.log(user["name"]);

  
*/
