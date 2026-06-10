#include "game.hpp"
#include <iostream>
#include <limits>

using namespace std;

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
      cout << "Bad Input Received. Please Try Again!" << endl;
      cin.clear();
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    isRoundOver = isWin(board) || isTie(board);
  }
  printBoard(board);
}
