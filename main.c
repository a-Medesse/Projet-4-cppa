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

                printf("Le joueur %c a gagné. Félicitations !\n", joueur[i]);

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
