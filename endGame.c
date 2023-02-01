
#include <stdio.h>

#include "game.h"
#include "endGame.h"
#include "initGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {
  // Initialize variables
  int symbolStreak = 0;
  int tempCol = 0;
  int tempRow= 0; 
  
  // Horizontal direction
  // Loop through the tic tac toe grid
  for(int row = 0; row < game->boardSize; row++){
    for(int col = 0; col < game->boardSize; col++){
      // Set a temporary column to the current column
      tempCol = col;
      // Reset the symbolStreak variable
      symbolStreak = 0;
      // If the current coordinate is equal to the current player symbol
      if(game->board[row][col] == symbol){
        // Add one to the symbolStreak variable
        symbolStreak += 1;
        // While the next column is less than the boardSize
        while((col+1) < game->boardSize){
          // Add one to the current column
          col += 1;
          // If the current coordinate is equal to the current player symbol
          if(game->board[row][col] == symbol){
            // Add one to the symbolStreak variable
            symbolStreak += 1;
            // If the symbolStreak is equal to the winning length
            if(symbolStreak == game->winLength){
              return 1;
            }
          }
        }
        // Reset the column to the temporary column
        col = tempCol;
      }
    }
  }

  // Vertical direction
  // Loop through the tic tac toe grid
  for(int row = 0; row < game->boardSize; row++){
    for(int col = 0; col < game->boardSize; col++){
      // Set a temporary row to the current row
      tempRow = row;
      // Reset the symbolStreak variable
      symbolStreak = 0;
      // If the current coordinate is equal to the current player symbol
      if(game->board[row][col] == symbol){
        // Add one to the symbolStreak variable
        symbolStreak += 1;
        // While the next row is less than the boardSize
        while((row+1) < game->boardSize){
          // Add one to the current row
          row += 1;
          // If the current coordinate is equal to the current player symbol
          if(game->board[row][col] == symbol){
            // Add one to the symbolStreak variable
            symbolStreak += 1;
            // If the symbolStreak is equal to the winning length
            if(symbolStreak == game->winLength){
              return 1;
            }
          }
        }
        // Reset the row to the temporary row
        row = tempRow;
      }
    }
  }

  // Horizontal direction
  // Loop through the tic tac toe grid
  for(int row = 0; row < game->boardSize; row++){
    for(int col = 0; col < game->boardSize; col++){
      // Set a temporary row to the current row
      tempRow = row;
      // Set a temporary column to the current column
      tempCol = col;
      // Reset the symbolStreak variable
      symbolStreak = 0;
      // If the current coordinate is equal to the current player symbol
      if(game->board[row][col] == symbol){
        // Add one to the symbolStreak variable
        symbolStreak += 1;
        // While the next column is less than the boardSize
        while(((row+1) < game->boardSize) && ((col+1) < game->boardSize)){
          // Add one to the current column and row
          row += 1;
          col += 1;
          // If the current coordinate is equal to the current player symbol
          if(game->board[row][col] == symbol){
            // Add one to the symbolStreak variable
            symbolStreak += 1;
            // If the symbolStreak is equal to the winning length
            if(symbolStreak == game->winLength){
              return 1;
            }
          }
        }
        // Reset the row and column to the temporary ones
        row = tempRow;
        col = tempCol;
      }
    }
  }
  return 0;
}






// test for a draw
int drawGame( Game *game ) {
  // Initialize variables
  int draw = 1;
  // Loop through the board
  for(int i = 0; i < game->boardSize; i++){
    for(int j = 0; j < game->boardSize; j++){
      // If there is an unused place of the board then set the draw variable to 0
      if(game->board[i][j] == '.'){
        draw = 0;
      }
    }
  }
  // If the draw variable is 1 then it is a draw, otherwise it doesn't
  if(draw == 1){
    return 1; // There is a draw
  }
  else{
    return 0; // continue
  }

  
}

