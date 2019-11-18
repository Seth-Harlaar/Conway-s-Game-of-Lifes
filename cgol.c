#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 20
#define COLS 40

int prettyPrint ( int printArray[ROWS][COLS], int tickCount);
int nextGen ( int seedArray[ROWS][COLS]);

int main(int argc, char *argv[]) {
  FILE *seedFile;

  int i, j;
  int ticks;
  int tickCount = 0;

  int seedArray[ROWS][COLS];


  char start[10];
  char yes[] = "y\n";
  char no[] = "n\n";

  /* check for correct # of input */
  if ( argc > 3 || argc < 1){
    printf("incorrect input \n");
  } else if (argc  == 3) {
    /* Get the tickCount */
    ticks = atoi(argv[2]);    
  } else {
    ticks = 50;
  }
  
  /* get the file name */
  seedFile = fopen(argv[1], "r");

  if (seedFile != NULL){
    printf("open success\n");
  } else {
    printf("file could not be found\n");
  }


  /* Go through the file and get the seed*/
  for (i = 0; i < ROWS; i++) {  
    for (j = 0; j < COLS; j++) {
      fscanf(seedFile, "%d", &seedArray[i][j]);
    }
  }     

  

  prettyPrint( seedArray , ticks );
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
    nextGen ( seedArray );
    tickCount++;
    ticks--;
    system ( "sleep 0.25" );

    if ( ticks == -1 ){
      printf("Continue? [y or n]: ");
      fgets(start, 10, stdin);
      while ( !(strcmp ( start, yes) == 0 || strcmp ( start, no) == 0 ) ){
        printf("Only the options yes (y) or no (n) are acceptable:");
        fgets(start, 10, stdin);

      }
      if ( strcmp ( start, no) == 0 ){
        return (0);
      } else {
        ticks += 50;
      }
    }

  }






  return 0;
}

