#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affiche(int tab[], int nb_pions) {
    int i;
    for (i = 0; i < nb_pions; i++) {
        printf("%i", tab[i]);
        if (i != nb_pions - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void lire(int tab[], int nb_pions, int nb_couleurs) {
    int i;

    for (i = 0; i < nb_pions; i++) {
        printf("valeurs:");
        do {
            scanf("%i", &tab[i]);
        } while(tab[i] < 0 || tab[i] >= nb_couleurs);
    }
    affiche(tab, nb_pions);
}

int bienplace(int joueur[], int machine[], int nb_pions) {
    int count = 0;
    int i = 0;

    for (i = 0; i < nb_pions; i++) {
        if (joueur[i] == machine[i]) {
            count++;
        }
    }
    return count;
}

int malplace(int joueur[], int machine[], int nb_pions, int nb_couleurs) {
    int malplaces = 0;
    int cj = 0;
    int cm = 0;
    int i, j;

    for (i = 1; i <= nb_couleurs; i++) {
        for (j = 0; j < nb_pions; j++) {
            if (joueur[j] != machine[j] && joueur[j] == i) {
                cj++;
            }
        }
        for (j = 0; j < nb_pions; j++) {
            if (joueur[j] != machine[j] && machine[j] == i) {
                cm++;
            }
        }
        if (cj < cm) {
            malplaces += cj;
        } else {
            malplaces += cm;
        }
        cj = 0;
        cm = 0;
    }
    return malplaces;
}

void init(int tab[], int nb_pions, int nb_couleurs) {
    int i;
    srand(time(NULL));

    for (i = 0; i < nb_pions; i++) {
        tab[i] = rand() % nb_couleurs;
    }
    /*affiche(tab, nb_pions);*/
}