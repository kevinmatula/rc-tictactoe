#include "game.hpp"
#include <iostream>

using namespace std;

const unordered_map<int, char> intToTeam = {{0, 'X'}, {1, 'O'}};

void fillBoard(char board[][BOARD_SIZE], char val) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = val;
    }
  }
}

bool allMatching(char arr[BOARD_SIZE]) {
  if (arr[0] == ' ') {
    return false;
  }

  for (int i = 1; i < BOARD_SIZE; i++) {
    if (arr[i] != arr[0]) {
      return false;
    }
  }
  return true;
}

void updateTurn(int &currentTurn) {
  if (currentTurn < (int)intToTeam.size() - 1) {
    currentTurn++;
  } else {
    currentTurn = 0;
  }
}

void updateBoard(char board[][BOARD_SIZE], int input, int &currentTurn) {
  int row = (input - 1) / BOARD_SIZE;
  int col = (input - 1) % BOARD_SIZE;
  int totalSquares = BOARD_SIZE * BOARD_SIZE;

  if (input > 0 && input <= totalSquares && board[row][col] == ' ') {
    board[row][col] = intToTeam.at(currentTurn);
    cout << endl;
    updateTurn(currentTurn);
  } else {
    cout << "Incorrect # or choice input. Please Try Again." << endl;
    cout << endl;
  }
}

void printBoard(char board[][BOARD_SIZE]) {
  int square = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    cout << string((BOARD_SIZE * 2) + 1, '-') << endl;
    cout << "|";
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] == ' ' ? cout << square : cout << board[i][j];
      cout << "|";
      square++;
    }
    cout << endl;
  }
  cout << string((BOARD_SIZE * 2) + 1, '-') << endl;
}

bool isWin(char board[][BOARD_SIZE]) {
  string winMessage = "Game Won! Congrats Team ";
  char horizontal[BOARD_SIZE] = {' '};
  char vertical[BOARD_SIZE] = {' '};
  char diagonalLeft[BOARD_SIZE] = {' '};
  char diagonalRight[BOARD_SIZE] = {' '};

  for (int row = 0; row < BOARD_SIZE; row++) {
    diagonalLeft[row] = board[row][row];
    diagonalRight[row] = board[row][(BOARD_SIZE - 1) - row];

    if (row == (BOARD_SIZE - 1)) {
      if (allMatching(diagonalLeft)) {
        cout << winMessage << diagonalLeft[0] << "!" << endl;
        return true;
      } else if (allMatching(diagonalRight)) {
        cout << winMessage << diagonalRight[0] << "!" << endl;
        return true;
      }
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
      horizontal[col] = board[row][col];
      vertical[col] = board[col][row];

      if (col == (BOARD_SIZE - 1)) {
        if (allMatching(horizontal)) {
          cout << winMessage << horizontal[0] << "!" << endl;
          return true;
        } else if (allMatching(vertical)) {
          cout << winMessage << vertical[0] << "!" << endl;
          return true;
        }
      }
    }
  }
  return false;
}

bool isTie(char board[][BOARD_SIZE]) {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == ' ') {
        return false;
      }
    }
  }
  cout << "The Game has Resulted in a Tie!" << endl;
  return true;
}
