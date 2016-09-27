#include <iostream>

using namespace std;

void printBoard(char tileState[]);
int getTile(char row, char column);
void setTile(char in[], int index, int currentPlayer);
void resetBoard(char in[]);
bool checkWin(char in[], char move);
bool checkTie(char in[]);


const char X_MOVE = 'X';
const char O_MOVE = 'O';
const char BLANK = ' ';

int main(){
  
  char tileState[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  int currentPlayer = 0;
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  bool quit = false;
  bool running = true;
  char move[3];
  
  cout << endl << "Welcome to the TicTacToe console arena!" << endl;
  
  while(running == true){
    printBoard(tileState);
    
    do
    {
      cout << endl << "Enter move: ";
      cin.getline(move, 3);
    } while(getTile(move[0], move[1]) == 9);
      
    setTile(tileState, getTile(move[0], move[1]), currentPlayer);
    
    if(currentPlayer == 0){
      if(checkWin(tileState, X_MOVE)){
	xWins++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	resetBoard(tileState);
	currentPlayer = 0;
      }
      else if(checkTie(tileState)){
	ties++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	resetBoard(tileState);
	currentPlayer = 0;
      }
      else{
	currentPlayer = 1;
      }
    }
    else{
      if(checkWin(tileState, O_MOVE)){
	oWins++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	resetBoard(tileState);
	currentPlayer = 0;
      }
      else if(checkTie(tileState)){
	ties++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	resetBoard(tileState);
	currentPlayer = 0;
      }
      else{
	currentPlayer = 0;
      }
    }
  }
  return 0;
}

void printBoard(char tileState[]){

  /*
    Board Positions
    0 | 1 | 2
    3 | 4 | 5
    6 | 7 | 8

   */
  
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
  else{
    return 9;
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

void resetBoard(char board[]){
  for(int i = 0; i < 9; i++){
    board[i] = ' ';
  }
}

bool checkWin(char board[], char move){
  if(board[0] == board[1] == move){
    cout << "equal" << endl;
  }
  else{
    cout << "not equal" << endl;
  }
  if(board[0] == board[1] == board[2] == move){
    return true;
  }
  else if(board[3] == board[4] == board[5] == move){
    return true;
  }
  else if(board[6] == board[7] == board[8] == move){
    return true;
  }
  else if(board[0] == board[3] == board[6] == move){
    return true;
  }
  else if(board[1] == board[4] == board[7] == move){
    return true;
  }
  else if(board[2] == board[5] == board[8] == move){
    return true;
  }
  else if(board[0] == board[4] == board[8] == move){
    return true;
  }
  else if(board[2] == board[4] == board[6] == move){
    return true;
  }
  else{
    return false;
  }
}

bool checkTie(char board[]){
  if(board[0] != BLANK && board[1] != BLANK &&
     board[2] != BLANK && board[3] != BLANK &&
     board[4] != BLANK && board[5] != BLANK &&
     board[6] != BLANK && board[7] != BLANK &&
     board[8] != BLANK){
    return true;
  }
  else{
    return false;
  }
}
