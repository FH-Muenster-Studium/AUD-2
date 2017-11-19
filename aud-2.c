//
// Created by Fabian Terhorst on 09.11.17.
//

#include "aud-2.h"
#include <stdio.h>
#include <stdlib.h>

int bedroht(int* schachbrett) {
    /* x==nach unten; y==nach rechts */
    int x, y;
    for (x = 0; x < 7; x++)
        /* Ist auf feld[x] eine Dame? */
        if (schachbrett[x])
            for (y = x + 1; y <= 7; y++)
                /* Ist auf feld[y] eine Dame? */
                if (schachbrett[y]) {
                    /* Wir überprüfen, ob die beiden
                     * Damen kollidieren. */
                    /* Sind beide Damen in derselben Zeile? */
                    if (schachbrett[x] == schachbrett[y])
                        return 1; /* Kollision in gleicher Zeile */
                    /* Diagonal? */
                    if (abs(x - y) == abs(schachbrett[x] - schachbrett[y]))
                        return 2; /* Kollision in der Diagonalen */
                }
    return 0; /* keine Kollision! */
}

int setze(int* schachbrett, int position) {
    int x = 1, i;
    static int counter = 1;

    while (x <= 8) {
        /* Wir setzen die Dame mit der
         * Nummer x an feld[position]. */
        schachbrett[position] = x;
        if (!bedroht(schachbrett)) {
            if (position) {
                /* die nächste Dame */
                if (setze(schachbrett, position - 1))
                    return 1; /* Dame an diese Position setzen */
            } else {
                printf("Loesungs-Nr.%2d : ", counter++);
                for (i = 0; i < 8; i++)
                    printf("(%d,%d)", i + 1, schachbrett[i]);
                printf("\n");
            }
        }
        x++;
    }
    schachbrett[position] = 0;
    return 0;
}