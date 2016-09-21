#include <iostream>

using namespace std;

void printBoard(char tileState[]);

int main(){
  
  char tileState[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  int currentPlayer = 0;
  char X_MOVE = 'X';
  char O_MOVE = 'O';
  char BLANK = ' ';
  cout << endl << "Welcome to the TicTacToe console arena!" << endl << endl;
  printBoard(tileState);
  
  return 0;
}

void printBoard(char tileState[]){
  cout << "The board:" << endl << endl << "  1 2 3" << endl << "a " << tileState[0] << " " <<
  tileState[1] << " " << tileState[2] << endl << "b " << tileState[3] << " " << tileState[4] <<
  " " << tileState[5] << endl << "c " << tileState[6] << " " << tileState[7] << " " <<
  tileState[8] << endl;
}
  
