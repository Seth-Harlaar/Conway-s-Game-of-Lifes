#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

void prettyPrint ( int printArray[ROWS][COLS], int tickCount) {

  int i, j, k;

  /* This prints out the seed in fancy way */
  for (k = 0; k < COLS + 2; k++) {
    printf("-");
  }

  printf( "\n" );
  for (i = 0; i < ROWS; i++) {
    printf("|");
    for (j = 0; j < COLS; j++) {
      if (printArray[i][j] == 1){
        printf( "X" );
      } else if (printArray[i][j] == 0){
        printf( " " );
      }
    }
    printf("|\n");
  }

  for (k = 0; k < COLS + 1; k++) {
    printf("-");
  }
  printf( "%d\n", tickCount );


}