#include <stdio.h>

#define BOUNDARY 64
#define ROWS 128

void test(void);

void display_array(char array[BOUNDARY][ROWS]);

void fill_array(char array[BOUNDARY][ROWS], char cell);

void initial_triangle(char array[BOUNDARY][ROWS], int y, int x, int levels);

void further_triangles(char array[BOUNDARY][ROWS], int y, int x, int levels);

void sierpinksi(char array[BOUNDARY][ROWS], int y, int x, int levels);

int main(void) {

    test();

    return 0; 

}

void test (void) {

    char test_sierpinksi[BOUNDARY][ROWS];

    fill_array(test_sierpinksi, '*');
    initial_triangle(test_sierpinksi, 0, 63, 64);
    sierpinksi(test_sierpinksi, 63, 63, 64);
    /*further_triangles(test_sierpinksi, 63, 63, 32);*/
    display_array(test_sierpinksi);

}

void sierpinksi(char array[BOUNDARY][ROWS], int y, int x, int levels) {


    /*Win condition*/
    if (levels == 0) {
        return;
    }

    levels = levels/2;

    further_triangles(array, y, x, levels);

    sierpinksi(array, y, x+levels, levels);
    sierpinksi(array, y, x-levels, levels);
    sierpinksi(array, y-levels, x, levels);

}

void display_array(char array[BOUNDARY][ROWS]) {

    int y, x;

    for (y = 0; y < BOUNDARY; y++) {
        printf("\n");
        for (x = 0; x < ROWS; x++) {

            /*if (array[y][x] == '#'){
                neillfgcol(magenta);
            }
            if (array[y][x] == '*') {
                neillfgcol(cyan);
            }*/
            
            printf("%c", array[y][x]);
        }
    }
    printf("\n");
}

void fill_array(char array[BOUNDARY][ROWS], char cell) {

    int y, x;

    for (y = 0; y < BOUNDARY; y++) {
        for (x = 0; x < ROWS; x++) {
            array[y][x] = cell;
        }
    }
}

void initial_triangle(char array[BOUNDARY][ROWS], int y, int x, int levels) {

    int j, i; 

    for (j = 0; j < levels; j++) {
            for (i = -j; i <= j; i++) {

                array[y + j][x + i] = ' '; 
            }
    }
}

void further_triangles(char array[BOUNDARY][ROWS], int y, int x, int levels) {

    int j, i; 


    for (j = 0; j < levels; j++) {
            for (i = -j; i <= j; i++) {

                array[y - j][x + i] = '*'; 
            }
    }

}

