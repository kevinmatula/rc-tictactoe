#pragma once
#include <unordered_map>

const int BOARD_SIZE = 3;
extern const std::unordered_map<int, char> intToTeam;

// This function populates the given board with whatever value is provided.
void fillBoard(char board[][BOARD_SIZE], char val);

// This function consumes a 1D array of chars and checks if all values are
// equal.
bool allMatching(char arr[BOARD_SIZE]);

// This function cycles through the player turns. The function is purposefully
// generic so more players can be added.
void updateTurn(int &currentTurn);

// This function takes in the game board, user input, team symbol, and updates
// the board.
void updateBoard(char board[][BOARD_SIZE], int input, int &currentTurn);

// This function consumes the board data and prints the board out into the
// console. This function works for arbitrarily large boards.
void printBoard(char board[][BOARD_SIZE]);

// This function checks the board (for arbitrarily large) to detect for a win.
// It works by checking specific row, columns, and diagonals.
bool isWin(char board[][BOARD_SIZE]);

// This function consumes a 2D array representing a board and checks if the game
// has resulted in a tie.
bool isTie(char board[][BOARD_SIZE]);
