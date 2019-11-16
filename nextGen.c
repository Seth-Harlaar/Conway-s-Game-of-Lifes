#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

int nextGen ( int seedArray[ROWS][COLS]) {

  int changeCount = 0;
  int i, j, x, y;
  int xBound, yBound;

  char nextArray[ROWS][COLS];


  /* Loop through all the cords, and apply rules to each one */
  for (i = 0; i < ROWS; i++) {
    int aliveCount;
    for (j = 0; j < COLS; j++) {
      /* have to set some boundaries for the x and y values, so they don't exceed the grid*/

      /* loop through all the nieghbours of the cord, and apply rules */
      /* x and y will be the relative cordinate to the cell focused on */
      for (x = - 1; x < 2; x++) {  
        for (y = - 1; y < 2; y++) {
          
        }
      }  
    }
  }
    



  return(changeCount);

}