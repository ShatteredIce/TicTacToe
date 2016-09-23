#include <iostream>

using namespace std;

void printBoard(char tileState[]);
int getTile(char row, char column);
void setTile(char in[], int index, int currentPlayer);

const char X_MOVE = 'X';
const char O_MOVE = 'O';
const char BLANK = ' ';

int main(){
  
  char tileState[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  int currentPlayer = 0;
  bool quit = false;
  bool running = true;
  char move[3];
  
  cout << endl << "Welcome to the TicTacToe console arena!" << endl;
  
  while(running == true){
    printBoard(tileState);

    cin.getline(move, 3);

    setTile(tileState, getTile(move[0], move[1]), currentPlayer);
    if(currentPlayer == 0){
      currentPlayer = 1;
    }
    else{
      currentPlayer = 0;
    }
  }
  return 0;
}

void printBoard(char tileState[]){
  cout << endl << "The board:" << endl << endl << "  1 2 3" << endl << "a " << tileState[0] << " " <<
  tileState[1] << " " << tileState[2] << endl << "b " << tileState[3] << " " << tileState[4] <<
  " " << tileState[5] << endl << "c " << tileState[6] << " " << tileState[7] << " " <<
  tileState[8] << endl;
}

int getTile(char row, char column){
  if(row == 'a' && column == '1'){
    return 0;
  }
  else if(row == 'a' && column == '2'){
    return 1;
  }
  else if(row == 'a' && column == '3'){
    return 2;
  }
  else if(row == 'b' && column == '1'){
    return 3;
  }    
  else if(row == 'b' && column == '2'){
    return 4;
  }
  else if(row == 'b' && column == '3'){
    return 5;
  }
  else if(row == 'c' && column == '1'){
    return 6;
  }
  else if(row == 'c' && column == '2'){
    return 7;
  }
  else if(row == 'c' && column == '3'){
    return 8;
  }  
}

void setTile(char in[], int index, int currentPlayer){
  if(currentPlayer == 0){
    in[index] = X_MOVE;
  }
  else{
    in[index] = O_MOVE;
  }
}

  
