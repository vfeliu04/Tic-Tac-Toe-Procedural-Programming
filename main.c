
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "game.h"
#include "initGame.h"
#include "playGame.h"


/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  Game *game; // pointer for the game structure
  int boardSize = atoi(argv[1]);
  int winLength = atoi(argv[2]);

  // If the amount of arguments given by the user is not three
  if((argc!= 3) || (boardSize == 0) || (winLength == 0)){
    // Exit
    return 1;
  }

  // Setting the variables boardSize and winLength to the arguments given by the user
  
  
  // Setting the pointer to function boardSize and winLength
  game = initGame(boardSize, winLength);
  
  
  // play a full game
  playGame(game);

  free(game); // free heap memory that was used

  return 0;
}

