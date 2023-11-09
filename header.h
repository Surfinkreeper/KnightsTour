#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
using namespace std;

const int BOARD_SIZE = 8;
const int EMPTY = 99;

bool solveKnightsTour(int board[][BOARD_SIZE], int row, int col, int move);
void printBoard(int board[][BOARD_SIZE]);
bool isValid(int board[][BOARD_SIZE], int row, int col);

void printBoard(int board[][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++) {
            cout << " " << setw(2) << setfill('0') << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool solveKnightsTour(int board[][BOARD_SIZE], int row, int col, int move) {
    
    if(!isValid(board, row, col)) {
        return false;
    }
    
    board[row][col] = move;
    //printBoard(board);
    
    if(move == 63) {
        printBoard(board);
        return true;
    }

    for(int i = 1; i <= 8; i++ ) {
        switch (i) {
            case 1:
                //cout << "ENTERED" << endl; 
                if(solveKnightsTour(board, row-1, col-2, move + 1)) {
                    return true;
                } 
                break;
            case 2: if(solveKnightsTour(board, row-1, col+2, move + 1)) {
                    return true;
                } 
                break;
            case 3: if(solveKnightsTour(board, row+1, col-2, move + 1)) {
                    return true;
                }
                break;
            case 4: if(solveKnightsTour(board, row+1, col+2, move + 1)) {
                    return true;
                }
                break;
            case 5: if(solveKnightsTour(board, row-2, col-1, move + 1)) {
                    return true;
                }
                break;
            case 6: if(solveKnightsTour(board, row+2, col-1, move + 1)) {
                    return true;
                } 
                break;
            case 7: if(solveKnightsTour(board, row-2, col-1, move + 1)) {
                    return true;
                } 
                break;
            case 8: if(solveKnightsTour(board, row+2, col+1, move + 1)) {
                    return true;
                } 
                break;
        }
    }

    board[row][col] = EMPTY;

    return false;
}

bool isValid(int board[][BOARD_SIZE], int row, int col) {
    

    //cout << "ENTERED IS VALID FUNCTION" << endl;
    //check to make sure youre still in the board
    if( row < 0 || row > 7 ) {
        //cout << "1 IS FALSE" << endl;
        return false;
    }
    if( col < 0 || col > 7 ) {
        //cout << "2 IS FALSE" << endl;
        return false;
    }

    //check to see if spot has already been moved to
    if( board[row][col] != EMPTY ) {
        //cout << "3 IS FALSE" << endl;
        return false;
    }

    return true;
}


#endif