/*

Jeux : 1

Le Nombre Caché

*/

#include <stdio.h>
#include <stdlib.h>

#include <time.h>

// Fonction aleatoire entre {min, max}
static int aleatoire(int min, int max) {
    if (min > max) {
        int tmp = min; min = max; max = tmp;
    }
    return min + rand() % (max - min + 1);
}

int main(void){

    // Initialisations des variables
    const int essais_max = 10;
    int Vmini = 500;
    int Vmaxi = 1000;
    int VMAX, N;
    int essais = 0;
    int trouve = 0;
    int points = 0;
    int proposition = 0;

    //
    // jsp si les deux marchent
    // ---> a corriger ici
    //

    srand((unsigned)time(NULL));
    // srand(time(NULL));

    // On determine VMAX et N, avec l'appelation de la fonction aleatoire qui est definie plus haut
    VMAX = aleatoire(Vmini, Vmaxi);
    N    = aleatoire(1, VMAX);

    // Le jeu commence , AFFICHAGE des instructions

    printf("=== JEU DU NOMBRE CACHE ===\n");                            // Titre du jeu
    printf("Trouvez le nombre cache entre 1 et %d\n", VMAX);            // Intervalle {1, VMAX}
    printf("Vous avez %d essais maximum.\n\n", essais_max);             // Essais max {essais_max}

    while (essais < essais_max && !trouve) {

        // affiche : Essai x/y - Votre proposition : n

        printf("Essai %d/%d - Votre proposition : ", essais + 1, essais_max);

        if (scanf("%d", &proposition) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Veuillez entrer un entier.\n\n");
            continue;
        }

        essais++;

        // verification de si la proposition est correcte

        if (proposition == N) {
            trouve = 1;
            points = essais;
            printf("\n*** BRAVO ! Vous avez trouve le nombre %d en %d essai(s) ! ***\n", N, essais);
            printf("Votre score : %d points\n", points);
        } else if (proposition < N) {
            printf("Le nombre cache est PLUS GRAND\n\n");
        } else {
            printf("Le nombre cache est PLUS PETIT\n\n");
        }
    }

    // si le joueur n'a pas trouve le nombre
    // point de penalite = 12

    if (!trouve) {
        points = 12;
        printf("\n*** PERDU ! ***\n");
        printf("Le nombre cache etait : %d\n", N);
        printf("Penalite : %d points\n", points);
    }

    return 0;
}
