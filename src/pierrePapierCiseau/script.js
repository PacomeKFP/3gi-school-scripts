const contenantChoixUtilisateur = document.getElementById("choix-utilisateur");
const contenantChoixOrdinateur = document.getElementById("choix-ordinateur");
const contenantResultat = document.getElementById("resultat");

const choixPossibles = document.querySelectorAll("button");
const pierreCiseauPapier = ["pierre", "ciseau", "papier"];

let choixUtilisateur;
let resultat;
let choixOrdinateur;

// Evenement 'Click' sur le boutton
choixPossibles.forEach((choixPossible) => {
  if (choixPossible.id !== "caller")
    choixPossible.addEventListener("click", (e) => {
      //récupération de l'ID du boutton cliqué
      choixUtilisateur = e.target.id;
      //On ajoute l'image qui correspond au choix
      contenantChoixUtilisateur.innerHTML =
        "<img src =assets/" + choixUtilisateur + ".png>";

      generer_choix_ordinateur();

      verification();
    });
});

//Fonction pour générer le choix de l'ordinateur
function generer_choix_ordinateur() {
  random = Math.floor(Math.random() * 3); //Générer des nombres compris entre 1 et 3

  choixOrdinateur = pierreCiseauPapier[random];

  //On ajoute l'image qui correspond au choix
  contenantChoixOrdinateur.innerHTML =
    "<img src =assets/" + choixOrdinateur + ".png>";
}

//Fonction pour vérifier si le joueur a gagné ou pas
function verification() {
  const user = pierreCiseauPapier.indexOf(choixUtilisateur),
    pc = pierreCiseauPapier.indexOf(choixOrdinateur);
  if (user === pc) resultat = "Egalité !";
  else if (user < pc || (user == 2 && pc == 0)) resultat = "Gagné !";
  else resultat = "Perdu !";

  contenantResultat.innerHTML = resultat;
}
