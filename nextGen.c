#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

int prettyPrint ( int printArray[ROWS][COLS], int tickCount);


int nextGen ( int seedArray[ROWS][COLS]) {

  int changeCount = 0;
  int j, i, x, y;
  int xLowerBound, xUpperBound, yLowerBound , yUpperBound;
  int aliveCount;

  int nextArray[ROWS][COLS];

  /* Loop through all the cords, and apply rules to each one */
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      aliveCount = 0;      

      /* have to set some boundaries for the x and y values, so they don't exceed the grid*/
      if ( i == ROWS ){
        yUpperBound = -1;
        yLowerBound = 0;
      } else if ( i == 0 ){
        yUpperBound = 0;
        yLowerBound = 1;
      } else {
        yUpperBound = -1;
        yLowerBound = 1;
      }

      if ( j == COLS ){
        xUpperBound = 0;
        xLowerBound = -1;
      } else if( j == 0 ){
        xUpperBound = 1;
        xLowerBound = 0;
      } else {
        xUpperBound = 1;
        xLowerBound = -1;
      }


      /* loop through all the nieghbours of the cord, and apply rules */
      /* x and y will be the relative cordinate to the cell focused on */
      for (y = yUpperBound; y < yLowerBound; y++) {
        for (x = xLowerBound; x < xUpperBound; x++) {  
          if ( !(x == 0 || y == 0) ) {
            /* count neighbours */
            if ( seedArray[y + i][x + j] == 1){
              aliveCount ++;
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

  prettyPrint ( nextArray, changeCount );

  return(changeCount);

}