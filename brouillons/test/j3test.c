#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int reponsejuste;
    char Voyelle[] = "aeiouyAEIOUY";
    int longueur = strlen(Voyelle);
    srand(time(NULL));
    char reponsejuste[4];

    for (int i = 0; i < 4; i++){
        int random = rand() % longueur;
        reponsejuste[i] = Voyelle[random];
    }

    printf("reponse juste : %s\n", reponsejuste);

/*
    for (int i = 0; i < 4; i++){
        reponsejuste = rand()%(sizeof(Voyelle)-1);
        printf("reponse juste %d : %c\n", i+1, Voyelle[reponsejuste]);}
/*
// reponsejuste[0] = rand()%(sizeof(Voyelle)-1);
// reponsejuste[1] = rand()%(sizeof(Voyelle)-1);
// reponsejuste[2] = rand()%(sizeof(Voyelle)-1);
// reponsejuste[3] = rand()%(sizeof(Voyelle)-1);

/*
    equivalent en algorithme:

    voyelle <- "aeiouyAEIOUY15154158452415241"
    aleatoire <- generer un nombre entre 0 et longueur(voyelle)-1

    reponsejuste[i] <- aleatoire
    reponsejuste ++1
    reponsejuste[i] <- aleatoire
    reponsejuste ++1
    reponsejuste[i] <- aleatoire
    reponsejuste ++1
    reponsejuste[i] <- aleatoire

    repeter
        reponsejuste[i] <- aleatoire
        reponsejuste ++1
    jusqu'a ce que n=0

*/

/*
    reponsejuste = 4*rand()%(sizeof(Voyelle)-1);
    printf("reponse juste : %d\n", reponsejuste);

*/
// on va devoir generer un nombre entre 1 et "Longueur de la chaine voyelle
// puis on va l'utiliserpour choisir une voyelle aleatoire

}
