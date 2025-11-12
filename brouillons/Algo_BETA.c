// ici repose tout les algos des jeux

// 1. Jeu du Nombre Caché
// 2. Jeu de la Suite Mystère
// 3. Jeu du Mastermind
// 4. Jeux de confrontation // gestionnaire des jeux

// voici un lien github ou se situe tous les codes sources :
// https://github.com/ahmetbsbnr/jeux-de-confrontation

/*Jeu : 1

EssaisMax <- 10
VMax <- aleatoire(500, 1000)
N <- aleatoire(1, VMax)
points <- 0
essais <- 0
trouve <- faux
proposition <- 0

tant que (essais < EssaisMax) et (non trouve) faire
    lire (proposition)
    essais <- essais + 1

    SI (proposition = N) alors
        trouve <- vrai
        ecrire ("*** BRAVO ! Vous avez trouve le nombre ", N, " en ", essais, " essai(s) ! ***")
    Sinon si (proposition < N) alors
        ecrire ("Le nombre cache est PLUS GRAND")
    Sinon
        ecrire ("Le nombre cache est PLUS PETIT")
    FinSi
FinTantQue

Si  trouve  alors
    points <- essais
    ecrire ("Votre score : ", points, " points")
Sinon
    points <- 12
    ecrire ("*** PERDU ! ***")
    ecrire ("Le nombre cache etait : ", N)
    ecrire ("Penalite : ", points, " points")
FinSi

*/

/*Jeu : 2*/

/*Jeu : 3*/

/*Jeu de Confrontation*/
