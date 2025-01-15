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
