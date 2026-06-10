#include <endian.h>
#include <iostream>
#include <limits>
#include <unordered_map>

using namespace std;

// Global Variables
const int BOARD_SIZE = 3;
const unordered_map<int, char> intToTeam = {{0, 'X'}, {1, 'O'}};

// This function populates the given board with whatever value is provided.
void fillBoard(char board[][BOARD_SIZE], char val) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = val;
    }
  }
}

// This function consumes a 1D array of chars and checks if all values are
// equal.
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

// This function cycles through the player turns. The function is purposefully
// generic so more players can be added.
void updateTurn(int &currentTurn) {
  if (currentTurn < intToTeam.size() - 1) {
    currentTurn++;
  } else {
    currentTurn = 0;
  }
}

// This function takes in the game board, user input, team symbol, and updates
// the board.
void updateBoard(char board[][BOARD_SIZE], int input, int &currentTurn) {
  int row = (input - 1) / BOARD_SIZE;
  int col = (input - 1) % BOARD_SIZE;
  int totalSquares = BOARD_SIZE * BOARD_SIZE;

  if (input > 0 && input <= totalSquares && board[row][col] == ' ') {
    board[row][col] = intToTeam.at(currentTurn);
    cout << "Placing Symbol at row: " << row << " and column: " << col << endl;
    cout << endl;
    updateTurn(currentTurn);
  } else {
    cout << "Incorrect # or choice input. Please Try Again." << endl;
    cout << endl;
  }
}

// This function consumes the board data and prints the board out into the
// console. This function works for arbitrarily large boards.
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

// This function checks the board (for arbitrarily large) to detect for a win.
// It works by checking specific row, columns, and diagonals.
bool isWin(char board[][BOARD_SIZE]) {
  char horizontal[BOARD_SIZE] = {' '};
  char vertical[BOARD_SIZE] = {' '};
  char diagonalLeft[BOARD_SIZE] = {' '};
  char diagonalRight[BOARD_SIZE] = {' '};

  for (int row = 0; row < BOARD_SIZE; row++) {
    diagonalLeft[row] = board[row][row];
    diagonalRight[row] = board[row][(BOARD_SIZE - 1) - row];

    if (row == (BOARD_SIZE - 1)) {
      string winMessage = "Game Won! Congrats Team ";
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
        string winMessage = "Game Won! Congrats Team ";
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

// This function consumes a 2D array representing a board and checks if the game
// has resulted in a tie.
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

int main() {
  char board[BOARD_SIZE][BOARD_SIZE];
  fillBoard(board, ' ');
  int currentTurn = 0;
  bool isRoundOver = false;
  int input;

  // Welcome message
  string message = "Welcome to Terminal Tic-Tac-Toe! This project was made for "
                   "Kevin Matula's Recurse Center Application!";

  string border(message.length(), '-');
  cout << border << endl;
  cout << message << endl;
  cout << border << endl;
  cout << "The rules are simple! Simply choose a # between 1-9 that has not "
          "yet been taken!"
       << endl;
  cout << endl;

  // Game Loop
  while (!isRoundOver) {
    cout << "It is Player " << currentTurn + 1 << "'s Turn! ("
         << intToTeam.at(currentTurn) << ")" << endl;
    printBoard(board);
    cout << "Numerically select a box: ";
    if (cin >> input) {
      updateBoard(board, input, currentTurn);
    } else {
      cout << "Bad Input Recieved. Please Try Again!" << endl;
      cin.clear();
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    isRoundOver = isWin(board) || isTie(board);
  }
  printBoard(board);
}
