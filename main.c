#include "aud-2.h"

int main() {
    int schachbrett[8], x;

    for (x = 0; x < 8; x++)
        schachbrett[x] = 0;
    setze(schachbrett, 7);
    return 0;
}