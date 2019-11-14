#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 3

int main(int argc, char *argv[]) {
  FILE *seedFile;

  int k = 0;
  int i, j;
  int tickCount;

  char seedArray[ROWS][COLS];
  char line[ROWS];

  /* check for correct # of input */
  if (argc != 3){
    printf("incorrect input\n");
    return 0;
  }
  
  /* get the file name */
  seedFile = fopen(argv[1], "r");

  if (seedFile != NULL){
    printf("open success\n");
  } else {
    printf("file could not be found\n");
  }

  /* Get the tickCount */
  tickCount = atoi(argv[2]);

  /* Go through the file and get the seed*/
  while ( k < ROWS ){
    if ( fgets( line, COLS + 3, seedFile ) != 0 ){
      for (i = 0; i < ROWS; i++) {
        printf("%s\n", line);
        sscanf(line, "%s" );

        for (j = 0; j < COLS; j++) {
          seedArray[i][j] = line[j];
        }
      }
    }
    k++;
    printf("gay2\n");
  }

  printf("gay\n");

  

  return 0;
}

