#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

int prettyPrint ( int printArray[ROWS][COLS], int tickCount);
int nextGen ( int seedArray[ROWS][COLS] );

int main(int argc, char *argv[]) {
  
  FILE *seedFile;

  int tickCount = 0;
  int ticks;
  int tickCountCont;
  int changeCount;
  int i, j;

  int seedArray[ROWS][COLS];

  char yes[] = "y\n";
  char no[] = "n\n";
  char start[10];

  /* check for correct # of input */
  if ( argc > 3 || argc < 1){
    printf("incorrect input \n");
  } else if (argc  == 3) {
    /* Get the tickCount */
    ticks = atoi(argv[2]);
  } else {
    ticks = 50;
  }
  tickCountCont = ticks;   
  
  /* get the file name */
  seedFile = fopen(argv[1], "r");

  if (seedFile == NULL){
    printf("file could not be found\n");
    return(0);
  }

  /* Go through the file and get the seed*/
  for (i = 0; i < ROWS; i++) {  
    for (j = 0; j < COLS; j++) {
      fscanf(seedFile, "%d", &seedArray[i][j]);
    }
  }

  prettyPrint( seedArray , tickCount );

  printf("Start? [y or n]: ");
  fgets(start, 10, stdin);
  while ( !(strcmp ( start, yes) == 0 || strcmp ( start, no) == 0 ) ){
    printf("Only the options yes (y) or no (n) are acceptable:");
    fgets(start, 10, stdin);
  }
  if ( strcmp ( start, no ) == 0 ){
    return (0);
  }  

  while ( ticks >= 0 ) {
    changeCount = nextGen( seedArray );

    if (changeCount == 0){
      /* terminate the program if nothing changes*/
      exit(0);
    }

    tickCount++;
    ticks--;

    prettyPrint( seedArray, tickCount );
    
    system ("sleep 0.25");

    if ( ticks == 0 ){
      printf("Continue? [y or n]: ");
      fgets(start, 10, stdin);
      while ( !(strcmp ( start, yes) == 0 || strcmp ( start, no) == 0 ) ){
        printf("Only the options yes (y) or no (n) are acceptable:");
        fgets(start, 10, stdin);
      }

      if ( strcmp ( start, no) == 0 ){
        exit(0);
      } else {
        ticks += tickCountCont;
      }
    }
  }

  return 0;
}

