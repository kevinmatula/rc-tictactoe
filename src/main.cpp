#include <iostream>
#include <limits>
#include <unordered_map>

using namespace std;

// Global Variables
const int BOARD_SIZE = 3;
unordered_map<int, char> intToTeam = {{0, 'X'}, {1, 'O'}};

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

  if (input > 0 && input < 10 && board[row][col] == ' ') {
    board[row][col] = intToTeam[currentTurn];
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
void printBoard(char board[][BOARD_SIZE], int rows) {
  int square = 1;
  for (int i = 0; i < rows; i++) {
    cout << "-------" << endl;
    cout << "|";
    for (int j = 0; j < 3; j++) {
      board[i][j] == ' ' ? cout << to_string(square) : cout << board[i][j];
      cout << "|";
      square++;
    }
    cout << endl;
  }
}

int main() {
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  int currentTurn = 0;
  bool isOver = false;
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
  while (!isOver) {
    cout << "It is Player " << currentTurn + 1 << "'s Turn! ("
         << intToTeam[currentTurn] << ")" << endl;
    printBoard(board, BOARD_SIZE);
    cout << "Numerically select a box: ";
    if (cin >> input) {
      updateBoard(board, input, currentTurn);
    } else {
      cout << "Bad Input Recieved. Please Try Again!" << endl;
      cin.clear();
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}
