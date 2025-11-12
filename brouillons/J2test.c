#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double U_iteratif(int n, int a, int b, int c) {
    double U = c;
    for (int i = 1; i <= n; i++) {
        U = a * U + b;
    }
    return U;
}

/*
exemple d'execution :

Bienvenue dans le jeu de la Suite Mystère !
Voici les 3 premiers termes de la suite :
U(0) = 3
U(1) = 10
U(2) = 31

À vous de jouer ! (2 essais)
Proposez une valeur pour U(3) : 94

Bravo ! Vous avez trouvé !

Vous marquez 1 point (trouvé au 1er essai).
Score de cette partie : 1
Score moyen actuel : 1.00

Voulez-vous rejouer ? (1 = oui / 0 = non) : 0

=== Fin du jeu ===
Vous avez joué 1 partie(s).
Score moyen final : 1.00

*/

// Programme Principal
int main() {
    srand(time(NULL));

    int rejouer = 1;
    int totalScore = 0;
    int nbParties = 0;

    printf("Bienvenue dans le jeu de la Suite Mystère !\n");

    do {
        // 1. Générer les coefficients aléatoires
        int a = (rand() % 7) + 1;
        int b = (rand() % 7) + 1;
        int c = (rand() % 7) + 1;

        int points = 0;

        printf("\n--- Nouvelle partie ---\n");

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
                if (essais_restants == 2)
                    points = 1;
                else
                    points = 2;
                essais_restants = 0;
            } else {
                printf("Dommage, ce n'est pas la bonne réponse.\n");
                essais_restants--;
                if (essais_restants == 0) {
                    printf("La bonne réponse était %.0f.\n", reponse_correcte);
                    printf("Vous avez une pénalité de 12 points.\n");
                    points = -12;
                }
            }
        }

        // Ajout du score au total
        totalScore += points;
        nbParties++;

        double moyenne = (double) totalScore / nbParties;

        printf("\nScore de cette partie : %d\n", points);
        printf("Score moyen actuel : %.2f\n", moyenne);

        // Demande de rejouer
        printf("\nVoulez-vous rejouer ? (1 = oui / 0 = non) : ");
        scanf("%d", &rejouer);

    } while (rejouer == 1);

    // Fin du jeu
    printf("\n=== Fin du jeu ===\n");
    double moyenneFinale = (double) totalScore / nbParties;
    printf("Vous avez joué %d partie(s).\n", nbParties);
    printf("Score moyen final : %.2f\n", moyenneFinale);

    return 0;
}
