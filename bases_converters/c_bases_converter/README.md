# Convertisseur de Bases

## Description

Ce projet est un programme en C qui permet de convertir des nombres entre différentes bases numériques en utilisant les divisions successives. Il propose des fonctions de conversion et des fonctions de verifications pour s'assurer que la conversion est possible (**validité des données**)

## Principe
Il permet à l'utilisateur de convertir un nombre d'une base initiale vers une base finale en passant par la base décimale. Lorsque l'utlisateur entre un nombre, le programme se charge d'effectuer les verifications et si la division est possible, on effectue la division comme au primaire 😅. C'est à dire on compare le chiffre le plus à gauche 0 à la base finale, si la division est possible, on la fait; sinon on ajoute le digit suivant. La comparaison se fait dans la base 10. Le reste de cette division et le quotient sont gardés en basee initiale et on continue la division jusqu'a obtenir un dernier reste etant à la fin du nombre. Le quotient de la division est encore divisé par la base finale. Ainsi de suite jusqu'a obtenir un quotient nul.
## Fonctions incluses

Le projet comprend les fonctions les fonctions suivantes :

### Fonctions principales

- `preprocessor.c` :  Ensemble des fonctions qui permettent de traiter l'entrée de l'utilisateur avant conversiont
- `router.c` : Ensemble des fonctions qui permettent de gerer les interactions avec l'utilisateur
- `converter.c`: Ensemble des fonctions aidant à la conversion

## Utilisation
Le programme principal se trouve dans le fichier _**main.c**_. Il demande à l'utilisateur de fournir la base initiale, la base finale et le nombre à convertir. Si le nombre est valide dans la base initiale, on effectue la conversion et on affiche le resultat à l'ecran.

## Compilation
Pour compiler le programme, il est necessaire d'avoir un compilateur C/C++ tel que gcc.
Dans notre cas nous utilisons `gcc`, la commande de compilation sera donc 
> `gcc src\main.c src\menu_handlers.c lib\*.c -o bin/app -I include` 

> Cette commande, à executer à la racine du projet, compilera l'ensemble des fichiers sources du projet et créera un fichier executable dans le dossier **/bin**
- Si vous etes sous windows, vous avez la possibilité de lancer juste le fichier **`run.bat`** qui contient un script bash permettant de compiler lancer directement l'application.
- Si vous etes sous windows et ne possedez pas de compilateur, vous a
