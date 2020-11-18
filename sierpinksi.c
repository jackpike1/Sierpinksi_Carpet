#include <stdio.h>
#include "neillsimplescreen.h"

#define BOUNDARY 81

void test(void);

void fill_hole(char array[BOUNDARY][BOUNDARY], int y, int x, int paint);

void fill_array(char array[BOUNDARY][BOUNDARY], char cell);

void display_array(char array[BOUNDARY][BOUNDARY]);

void sierpinksi(char array[BOUNDARY][BOUNDARY], int y, int x, int paint, int travel);

int main (void) {

    test();

    return 0; 

}

void test(void) {

    char test_sierpinski[BOUNDARY][BOUNDARY];

    fill_array(test_sierpinski, '*');

    sierpinksi(test_sierpinski, 40, 40, 13, 81);

    display_array(test_sierpinski);

}

void sierpinksi(char array[BOUNDARY][BOUNDARY], int y, int x, int paint, int travel) {

    int j, i;
    
    /* Win condition*/
    if (travel < 3) {
        /*display_array(array);*/
        return;
    }

    fill_hole(array, y, x, paint);

    /* distance to travel to newer, smaller square\
    how much of new square to paint*/
    travel = travel/3;
    paint = paint - travel/3;


    for (j = -1; j <= 1; j++) {
        for (i = -1; i <= 1; i++) {

            sierpinksi(array, y+(j*travel), x+(i*travel), paint, travel);
        }
    }           
}

void fill_hole(char array[BOUNDARY][BOUNDARY], int y, int x, int paint) {

    int j, i;

    for (j = -paint; j <= paint; j++) {
        for (i = -paint; i <= paint; i++) {

            array[y + j][x + i] = '#';

        }
    }
}

void fill_array(char array[BOUNDARY][BOUNDARY], char cell) {

    int y, x;

    for (y = 0; y < BOUNDARY; y++) {
        for (x = 0; x < BOUNDARY; x++) {
            array[y][x] = cell;
        }
    }
}

void display_array(char array[BOUNDARY][BOUNDARY]) {

    int y, x;

    for (y = 0; y < BOUNDARY; y++) {
        printf("\n");
        for (x = 0; x < BOUNDARY; x++) {

            if (array[y][x] == '#'){
                neillfgcol(magenta);
            }
            if (array[y][x] == '*') {
                neillfgcol(cyan);
            }
            
            printf("%c", array[y][x]);
        }
    }
    printf("\n");
}

