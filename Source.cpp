/*
* File: MP3
* Author: Anna Keeler
* Date: 11/5/2025
*
* Description: MP3 tic tac toe project.  two people play a game of tic tac toe.  Asks for moves alternately from each player, crosses or circles.
players cannot change what they are, even between games. board changes with each move. say who won or tied and ask to play again or quit. alternates
who plays first. keeps track of stats. NO TWO DIMENSIONAL ARRAYS, NO COUTS IN FUNCTIONS UNLESS IT IS A DISPLAY FUNCTION, MINIMIZE GLOBAL VARIABLES,
ASK NAMES AT BEGINNING
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

//prototypes
int getPlayerInput(string playerName);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);

void decidesPlayerTurn(string playerStart, string currentPlayer);



//global variables
const int SIZE = 9;
char boardArrayOne[SIZE] = { '7','8','9','4','5','6','1','2','3' };
char dummyArray[SIZE] = { '7','8','9','4','5','6','1','2','3' };

string name1;
string name2;
//int playerMarkSpace; //how to do location?
int location;


int main(void) {
    //variable definitions
    char playerMark = 'o';
    int ties = 0;
    int player1Score = 0;
    int player2Score = 0;
    char yesOrNo;
    char currentPlayerMark;
    int termCounter = 0;


    //asks players names

    cout << "Player 1's Name: ";
    getline(cin, name1);
    cout << "Player 2's Name: ";
    getline(cin, name2);
    string currentPlayer = name1;
    string playerStart = currentPlayer;
    while (true) {
        char playerMark1 = 'x';
        char playerMark2 = 'o';
        int playerSpace;
        if (currentPlayer == name1) {

            //gets players inputs and plays game
            //this loop repeats until one player has three in a row
             // what goes in brackets
            /*if (isLegalMove(boardArrayOne, playerSpace) == false) {
                cout << "I'm sorry, that's not a legal move." << endl;
            }*/
            //player one turn
            displayBoard(boardArrayOne);
            cout << name1 << "'s turn." << endl;
            playerSpace = getPlayerInput(name1);
            termCounter += 1;
            placeMarkOnBoard(boardArrayOne, playerMark1, playerSpace);
            if (hasThreeInRow(boardArrayOne, 'x') == true) {
                cout << name1 << " has won!" << endl;
                player1Score += 1;
                displayGameStats(ties, player1Score, player2Score);
                cout << "Would you like to play again? (Y/N)" << endl;
                cin >> yesOrNo;
                if (yesOrNo == 'Y') {
                    clearBoard(boardArrayOne);//play game again, do i use break?
                    decidesPlayerTurn(playerStart, currentPlayer);
                }
                if (yesOrNo == 'N') {
                    return 0;
                }
            }
            currentPlayer = name2;



            //else {
            //   
            //}
            //


        //hasThreeInRow(boardArrayOne, 'x') == false

        }

        if (hasThreeInRow(boardArrayOne, 'o') == false && hasThreeInRow(boardArrayOne, 'x') == false && termCounter == 9) {
            cout << "It was a tie!" << endl;
            ties += 1;
            displayGameStats(ties, player1Score, player2Score);
            cout << "Would you like to play again? (Y/N)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y') {
                clearBoard(boardArrayOne);
                decidesPlayerTurn(playerStart, currentPlayer);
            }
            if (yesOrNo == 'N') {
                return 0;
            }

        }
        if (currentPlayer == name2) {
            //gets players inputs and plays game
            //this loop repeats until one player has three in a row

                /*if (isLegalMove(boardArrayOne, location) == false) {
                    cout << "I'm sorry, that's not a legal move." << endl;
                }*/

                //player two turn
            displayBoard(boardArrayOne);
            cout << name2 << "'s turn." << endl;
            playerSpace = getPlayerInput(name2);
            termCounter += 1;
            placeMarkOnBoard(boardArrayOne, playerMark2, playerSpace);

            if (hasThreeInRow(boardArrayOne, 'o') == true) {
                cout << name2 << " has won!" << endl;
                player2Score += 1;
                displayGameStats(ties, player1Score, player2Score);
                cout << "Would you like to play again? (Y/N)" << endl;
                cin >> yesOrNo;
                if (yesOrNo == 'Y') {
                    clearBoard(boardArrayOne);//play game again, do i use break?
                    decidesPlayerTurn(playerStart, currentPlayer);
                }
                if (yesOrNo == 'N') {
                    return 0;
                }

            }

            currentPlayer = name1;


        }

        if (hasThreeInRow(boardArrayOne, 'o') == false && hasThreeInRow(boardArrayOne, 'x') == false && termCounter == 9) {
            cout << "It was a tie!" << endl;
            ties += 1;
            displayGameStats(ties, player1Score, player2Score);
            cout << "Would you like to play again? (Y/N)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y') {
                clearBoard(boardArrayOne);
                decidesPlayerTurn(playerStart, currentPlayer);
            }
            if (yesOrNo == 'N') {
                return 0;
            }

        }
    }
    //if a player has three in a row, end the game and show statistics,
    //ask if players want to play again





    return 0;
}

//returns a value between 1 and 9, inclusive, indicating the square where the current player wants to place his or her mark on the board.  
// The input routine is to use the name of the player whose turn it is and is to check for correct input. You may assume that the input is an integer,
// but the value entered might be where a mark on the board already exists.


int getPlayerInput(string playerName) {
    int playerMarkSpace;
    cout << "Please enter a number where you would like to place a mark: ";
    cin >> playerMarkSpace;

    return playerMarkSpace;
}
//Returns true if the indicated location on the board yet not yet been played, false otherwise

bool isLegalMove(char board[], int location) {
    //board[location];

    if (location == 'x' || location == 'o') {
        return false;
    }
    if (getPlayerInput(name1) > 9 || getPlayerInput(name2) > 9 || getPlayerInput(name1) <= 0 || getPlayerInput(name2) <= 0) {
        return false;
    }
    else return true;

}

//Places the indicated mark at the specified board location; routine assumes that this is legal placement
void placeMarkOnBoard(char board[], char playerMark, int location) {
    string playerName = name1;

    int i = 0;
    char locationChar = '0' + location;
    for (; i < board[i]; i++) {
        if (board[i] == locationChar) {
            location = i;
            break;
        }


    }
    board[i] = playerMark;



    return;
}

//Restores the tic tac toe board to its original (ie with no crosses or circles being marked) configuration
void clearBoard(char board[]) {

    // use a for loop to set each value in dummy array = to boardArrayOne[]
    for (int i = 0; i < SIZE; i++) {
        board[i] = dummyArray[i];
    }
    return;
}

//Returns true if, for the specified mark, the board has the equivalnet of three of thos emarks in a row, either vertically, horizontally, or diagonally
bool hasThreeInRow(char board[], char playerMark) {

    //if index = 0, and index =10, and index = 20 are all the same character, then return true; also true for every other possible position has three in a row
    if (board[0] == playerMark && board[1] == playerMark && board[2] == playerMark) {
        return true;
    }
    if (board[3] == playerMark && board[4] == playerMark && board[5] == playerMark) {
        return true;
    }
    if (board[6] == playerMark && board[7] == playerMark && board[8] == playerMark) {
        return true;
    }
    if (board[0] == playerMark && board[3] == playerMark && board[6] == playerMark) {
        return true;
    }
    if (board[1] == playerMark && board[4] == playerMark && board[7] == playerMark) {
        return true;
    }
    if (board[2] == playerMark && board[5] == playerMark && board[8] == playerMark) {
        return true;
    }
    if (board[0] == playerMark && board[4] == playerMark && board[8] == playerMark) {
        return true;
    }
    if (board[2] == playerMark && board[4] == playerMark && board[6] == playerMark) {
        return true;
    }
    return false;

}

//Prints out the current board; the board display must be as shown above, THIS WORKS DON'T CHANGE
void displayBoard(char board[]) {
    int rows = 3;
    int columns = 3;
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cout << " " << board[row * columns + column] << " ";

            if (column < 2) {
                cout << "|";
            }
            else {
                cout << endl;
            }
        }

        if (row < 2) {
            cout << "---+---+---" << endl;
        }


    }
    return;
}

//Prints out the "stats" for all the games: number of games tied, number of games player 1 won, and number ofgames player 2 won.  May include players' 
// names
void displayGameStats(int ties, int player1Score, int player2Score) {
    cout << "Ties: " << ties << endl;
    cout << name1 << "'s Score: " << player1Score << endl;
    cout << name2 << "'s Score: " << player2Score << endl;
    return;
}

void decidesPlayerTurn(string playerStart, string currentPlayer) {
    if (playerStart == name1) {
        playerStart = name2;
        currentPlayer = name2;
    }
    if (playerStart == name2) {
        playerStart = name1;
        currentPlayer = name1;
    }
    return;
}

