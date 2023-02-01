
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Initialize game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {
  
  Game *game;
  

  // for incorrect boardSize or winLength you should return a NULL pointer
  if(boardSize > 8 || winLength > boardSize || boardSize < 3){
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }
  else{
    // Allocate the Game data structure
    game =(Game *)malloc(sizeof(Game));
    // Initialise the Game data structure values 
    game->boardSize = boardSize;
    game->winLength = winLength;
    

    
    

    // board values should be set to '.' (unused location)
    // Loop through the board values and set them to '.'
    for(int row = 0; row < game->boardSize; row++){
      for(int col = 0; col < game->boardSize; col++){
        game->board[row][col] = '.';
      }
    }
    
    
    
    return game;
  }
  
}


