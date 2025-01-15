//
//  main.c
//  Jeu de morpion
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialiser_grille(char grille[3][3] ){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grille[i][j] = ' ';
        }
    }
}
void choix(char grille[3][3], char symbole) {

    int x, y;

    char buffer[100];

    do {

        printf("Entrez l'abscisse(entre 0, 1 et 2):");

        if(scanf("%d", &x) != 1) {

            printf("Coordonnée non valide. Veuillez réessayer.\n");

            scanf("%s", buffer);

            continue;

        }

        printf("Entrez l'ordonnée(entre 0, 1 et 2):");

        if(scanf("%d", &y) != 1) {

            printf("Coordonnée non valide. Veuillez réessayer.\n");

            scanf("%s", buffer);

            continue;

        }

        if (x<0 || x>2 || y<0 || y>2) {

            printf("Coordonnées non valides. Veuillez réessayer.\n");

        }

        else if(grille[x][y]!=' '){

            printf("Cette case occupée, veuillez réessa…
void afficher_grille(char grille[3][3]) {

    printf("\n 0   1   2 <- colonnes\n");

       for (int i = 0; i < 3; i++) {

           printf(" %d |", i);

           for (int j = 0; j < 3; j++) {

               printf(" %c |", grille[i][j]);

           }

           printf("\n  +---+---+---+\n");

       }

       printf("^\n|\nlignes\n");

}

s
int case_vide(char grille[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (grille[i][j]==' '){
                return 1;
            }


        }
    }
    return 0;
}


int verifier_gagnant(char grille[3][3], char symbole) {
    for (int i = 0; i < 3; i++) {
        if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole) {
            return 1;
        }
    }

        for (int j = 0; j < 3; j++) {
        if (grille[0][j] == symbole && grille[1][j] == symbole && grille[2][j] == symbole) {
            return 1;
        }
    }

        if (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole) {
        return 1;
    }
    if (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole) {
        return 1;
    }

    return 0;
}
void jouer_partie(char grille[3][3]) {

    char joueur[2] = {'A', 'B'};

    char symbole[2] = {'X', 'O'};



    initialiser_grille(grille);

    printf("Bienvenue dans cette partie de morpion.\nJoueur A (X) \t Joueur B (O)\n");



    while (1) {

        for (int i = 0; i < 2; i++) {

            afficher_grille(grille);

            printf("\nC'est au tour du joueur %c (%c)\n", joueur[i], symbole[i]);

            choix(grille, symbole[i]);



            if (verifier_gagnant(grille, symbole[i])) {

                afficher_grille(grille);

                printf("Le joueur %c a gagn�. F�licitations !\n", joueur[i]);

                return;

            }



            if (!case_vide(grille)) {

                afficher_grille(grille);

                printf("Match nul !\n");

                return;

            }

        }

    }

}

int main(int argc, const char * argv[]) {
    char rejouer;
    char grille[3][3];

        do {
            jouer_partie(grille);

            printf("Voulez-vous rejouer ? (o/n) : ");
            scanf(" %c", &rejouer);
        } while (rejouer == 'o' || rejouer == 'O');

        printf("Courage ! Au revoir !\n");
        return 0;
}
