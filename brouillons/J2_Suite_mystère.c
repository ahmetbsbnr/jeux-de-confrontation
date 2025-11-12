#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
a faire :

-- demande de rejouer
 L> si oui, relancer le jeu (avec nouvelles valeurs aleatoires)
 L> si non, afficher le score moyen des parties jouees
-- calcul du score moyen
 L> additionner les scores de chaque partie
 L> diviser par le nombre de parties jouees

*/

// Fonction pour calculer U(n) de la suite définie par récurrence
double U_iteratif(int n, double a, double b, double c) {
    double U_actuel = c;
    for (int i = 1; i <= n; i++) {
        U_actuel = a * U_actuel + b;
    }
    return U_actuel;
}

// Programme Principal
int main() {
    srand(time(NULL));

    // 1. Générer les coefficients a, b, c entre 1 et 7
    int a = (rand() % 7) + 1;
    int b = (rand() % 7) + 1;
    int c = (rand() % 7) + 1;

    //  nb points de cette partie.
    int points = 0;

    // DEBUG, on afficher les valeurs
    // printf("Valeurs secrètes : a=%d, b=%d, c=%d\n", a, b, c);

    printf("Bienvenue dans le jeu de la Suite Mystère !\n");
    printf("Voici les 3 premiers termes de la suite :\n");

    double U0 = U_iteratif(0, a, b, c);
    double U1 = U_iteratif(1, a, b, c);
    double U2 = U_iteratif(2, a, b, c);

    printf("U(0) = %.0f\n", U0);
    printf("U(1) = %.0f\n", U1);
    printf("U(2) = %.0f\n", U2);

    double reponse_correcte = U_iteratif(3, a, b, c);
    double reponse_joueur;
    int essais_restants = 2;

    printf("\nÀ vous de jouer ! (2 essais)\n");

    while (essais_restants > 0) {
        printf("Proposez une valeur pour U(3) : ");
        scanf("%lf", &reponse_joueur);

        if (reponse_joueur == reponse_correcte) {
            printf("Bravo ! Vous avez trouvé !\n");

            if (essais_restants == 2) {
                printf("Vous marquez 1 point (trouvé au 1er essai).\n");
                points = 1;
            } else {
                printf("Vous marquez 2 points (trouvé au 2e essai).\n");
                points = 2;
            }
            essais_restants = 0;
        } else {
            printf("Dommage, ce n'est pas la bonne réponse.\n");
            essais_restants = essais_restants - 1;

            if (essais_restants == 0) {
                printf("Vous n'avez plus d'essais.\n");
                printf("La bonne réponse était %.0f.\n", reponse_correcte);
                printf("Vous avez une pénalité de 12 points.\n");

                points = -12;
            }
        }
    }

    // Score final
    printf("\nScore pour cette partie : %d points\n", points);

    return 0;
}
