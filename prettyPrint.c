#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

void prettyPrint ( int printArray[ROWS][COLS], int tickCount) {

  int i, j, k;

  system( "clear" );

/* This shit prints out the seed in fancy way */
  for (k = 0; k < COLS + 2; k++) {
    printf("-");
  }

  printf( "\n" );
  for (i = 0; i < ROWS; i++) {
    printf("|");
    for (j = 0; j < COLS; j++) {
      printf( "%d", printArray[i][j]);
    }
    printf("|\n");
  }

  for (k = 0; k < COLS + 1; k++) {
    printf("-");
  }
  printf( "%d\n", tickCount );


}