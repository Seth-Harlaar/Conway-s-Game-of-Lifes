#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

int prettyPrint ( int printArray[ROWS][COLS], int tickCount);


int nextGen ( int seedArray[ROWS][COLS]) {

  int changeCount = 0;
  int i, j, x, y;
  int aliveCount;

  int nextArray[ROWS][COLS];
  int xCord;
  int yCord;

  /* Loop through all the cords, and apply rules to each one */
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      aliveCount = 0;

      /* have to set some boundaries for the x and y values, so they don't exceed the grid*/
      for (y = -1; y < 2; y++) {
        for (x = -1; x < 2; x++) {
          if ( !(x == 0 && y == 0) ) {
            yCord = i + y;
            xCord = j + x;
            if ( !(xCord < 0 || xCord > 39 || yCord < 0 || yCord > 19) ){
              /* count neighbours */
              if ( seedArray[yCord][xCord] == 1){
                aliveCount ++;
              }  
            }
          }
        }
      }

      /* now apply rules to cells */
      if ( seedArray[i][j] == 1 ){
        /* therefore cell is alive, and rules hould be applies as such */
        if ( aliveCount < 2 ){
          /* cell must die */
          nextArray[i][j] = 0;
          changeCount++;
        }
        if ( aliveCount == 2 || aliveCount == 3){
          /* cell may live */
          nextArray[i][j] = 1;
        }
        if ( aliveCount > 3){
          /* cell must die */
          nextArray[i][j] = 0;
          changeCount++;
        }
      } else if ( seedArray[i][j] == 0 ){
        /* cell is dead and only one rule applies */
        if ( aliveCount == 3 ){
          /* cell may come alive */
          nextArray[i][j] = 1;
          changeCount++;
        } else {
          /* new cell stays dead */
          nextArray[i][j] = 0;
        }
      }
    }
  }

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      seedArray[i][j] = nextArray[i][j];
    }
  }

  printf("Number of elements: %lu \n", sizeof(nextArray) / sizeof(nextArray[0]) );

  return( changeCount );

}