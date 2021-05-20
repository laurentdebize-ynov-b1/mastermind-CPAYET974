#include <stdio.h>
#include "fonctions.c"
#include "fonctions.h"

int main() {
    int machine[5], joueur[5];
    int nbcoups = 0, bp, mp;

    init(machine, 5, 7);
    do {
        lire(joueur, 5, 7);
        nbcoups++;
        bp = bienplace(joueur, machine, 5);
        mp = malplace(joueur, machine, 5, 7);
    } while(bp != 5);
    printf("%i\n", nbcoups);
    return 0;
}
