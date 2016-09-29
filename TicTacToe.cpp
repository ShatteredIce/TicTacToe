//C++ Project 3 - Nathan Purwosumarto - 9/29/16
//TicTacToe - Plays a game of tictactoe in the console

#include <iostream>

using namespace std;

//functions
void printBoard(char tileState[]);
int getTile(char in[], char row, char column);
void setTile(char in[], int index, int currentPlayer);
void resetBoard(char in[]);
bool checkWin(char in[], char move);
bool checkTie(char in[]);

//tile states
const char X_MOVE = 'X';
const char O_MOVE = 'O';
const char BLANK = ' ';

int main(){

  //setup variables
  char tileState[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  int currentPlayer = 0;
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  bool quit = false;
  bool running = true;
  char playAgain = 'n';
  char move[3];
  
  cout << endl << "Welcome to the TicTacToe console arena!" << endl;

  //game loop
  while(running == true){
    printBoard(tileState);
    cout << endl;
    do
    {
      cout << "Enter move: ";
      cin.getline(move, 3);
    } while(getTile(tileState, move[0], move[1]) == 9);

    setTile(tileState, getTile(tileState, move[0], move[1]), currentPlayer);

    //If current player is X
    if(currentPlayer == 0){
      //If board is in a winning state, update wins and prompt user if they want to play again
      if(checkWin(tileState, X_MOVE)){
	xWins++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	cout << endl << "Do you wish to play again? (y/n)" << endl;
	playAgain = 'n';
	cin >> playAgain;
	if(playAgain != 'y'){
	  running = false;
	  cout << "Program terminated.";
	  return 0;
	}
	resetBoard(tileState);
	currentPlayer = 0;
      }
      //If board is full, update ties and prompt user if they want to play again
      else if(checkTie(tileState)){
	ties++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	playAgain = 'n';
	cout << endl << "Do you wish to play again? (y/n)" << endl;
	cin >> playAgain;
	if(playAgain != 'y'){
	  running = false;
	  cout << "Program terminated.";
	  return 0;
	}
	resetBoard(tileState);
	currentPlayer = 0;
      }
      //If nobody has won, move on to next player
      else{
	currentPlayer = 1;
      }
    }
    //If current player is O
    else{
      //If board is in a winning state, update wins and prompt user if they want to play again
      if(checkWin(tileState, O_MOVE)){
	oWins++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	cout << endl << "Do you wish to play again? (y/n)" << endl;
	playAgain = 'n';
	cin >> playAgain;
	if(playAgain != 'y'){
	  running = false;
	  cout << "Program terminated.";
	  return 0;
	}
	resetBoard(tileState);
	currentPlayer = 0;
      }
      //check for a tie (same as currentPlayer = X)
      else if(checkTie(tileState)){
	ties++;
	printBoard(tileState);
	cout << endl << '\t' << "X Wins: " << xWins << '\t' << "O Wins: " << oWins
	     << '\t' << "Ties: " << ties << endl;
	cout << endl << "Do you wish to play again? (y/n)" << endl;
	playAgain = 'n';
	cin >> playAgain;
	if(playAgain != 'y'){
	  running = false;
	  cout << "Program terminated.";
	  return 0;
	}
	resetBoard(tileState);
	currentPlayer = 0;
      }
      //If nobody has won, move on to next player
      else{
	currentPlayer = 0;
      }
    }
  }
  return 0;
}

//Prints out the board to the console
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

//Converts user input to board index, a return of int 9 indicates illegal move 
int getTile(char board[], char row, char column){
  int tile = 9;
  if(row == 'a' && column == '1'){
    tile = 0;
  }
  else if(row == 'a' && column == '2'){
    tile = 1;
  }
  else if(row == 'a' && column == '3'){
    tile = 2;
  }
  else if(row == 'b' && column == '1'){
    tile = 3;
  }
  else if(row == 'b' && column == '2'){
    tile = 4;
  }
  else if(row == 'b' && column == '3'){
    tile = 5;
  }
  else if(row == 'c' && column == '1'){
    tile = 6;
  }
  else if(row == 'c' && column == '2'){
    tile = 7;
  }
  else if(row == 'c' && column == '3'){
    tile = 8;
  }
  //makes sure that move is legal
  if(tile != 9 && board[tile] != BLANK){
    return 9;
  }
  else{
    return tile;
  }
}

//sets the tile in the board array
void setTile(char in[], int index, int currentPlayer){
  if(currentPlayer == 0){
    in[index] = X_MOVE;
  }
  else{
    in[index] = O_MOVE;
  }
}

//clears board array to blanks
void resetBoard(char board[]){
  for(int i = 0; i < 9; i++){
    board[i] = BLANK;
  }
}

//check if board is in a winning state
bool checkWin(char board[], char move){
  if(board[0] == board[1] && board[0] == board[2] && board[0] == move){
    return true;
  }
  else if(board[3] == board[4] && board[3] == board[5] && board[3] == move){
    return true;
  }
  else if(board[6] == board[7] && board[6] == board[8] && board[6] == move){
    return true;
  }
  else if(board[0] == board[3] && board[0] == board[6] && board[0] == move){
    return true;
  }
  else if(board[1] == board[4] && board[1] == board[7] && board[1] == move){
    return true;
  }
  else if(board[2] == board[5] && board[2] == board[8] && board[2] == move){
    return true;
  }
  else if(board[0] == board[4] && board[0] == board[8] && board[0] == move){
    return true;
  }
  else if(board[2] == board[4] && board[2] == board[6] && board[2] == move){
    return true;
  }
  else{
    return false;
  }
}

//check if the board is full
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
