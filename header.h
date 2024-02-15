/************************************************************************
 * KnightsTour
 * Project by Daniel Salameh
 * 
 * This program solves the classic KnightTour problem. It is created using
 * proper recurrsive methods. ** BOARD_SIZE is configurable **
 * 
*************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int BOARD_SIZE = 8; //IS CONFIGURABLE -- may significantly increase runtime
const int EMPTY = 99;

bool solveKnightsTour(vector<vector<int>>& board, int row, int col, int move);
void printBoard(const vector<vector<int>>& board);
bool isValid(const vector<vector<int>>& board, int row, int col);

void printBoard(const vector<vector<int>>& board) {
    cout << BOARD_SIZE << " x " << BOARD_SIZE << " Knights Tour solution:" << endl;
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++) {
            cout << " " << setw(2) << setfill('0') << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool solveKnightsTour(vector<vector<int>>& board, int row, int col, int move) {

    if(!isValid(board, row, col)) {
        return false;
    }
    
    board[row][col] = move;
    
    if(move == (BOARD_SIZE*BOARD_SIZE-1)) {
        printBoard(board);
        return true;
    }

    for(int i = 1; i <= 8; i++ ) {
        switch (i) {
            case 1:
                if(solveKnightsTour(board, row+1, col+2, move + 1)) {
                    return true;
                } 
                break;
            case 2: if(solveKnightsTour(board, row+2, col+1, move + 1)) {
                    return true;
                } 
                break;
            case 3: if(solveKnightsTour(board, row+2, col-1, move + 1)) {
                    return true;
                }
                break;
            case 4: if(solveKnightsTour(board, row+1, col-2, move + 1)) {
                    return true;
                }
                break;
            case 5: if(solveKnightsTour(board, row-1, col-2, move + 1)) {
                    return true;
                }
                break;
            case 6: if(solveKnightsTour(board, row-2, col-1, move + 1)) {
                    return true;
                } 
                break;
            case 7: if(solveKnightsTour(board, row-2, col+1, move + 1)) {
                    return true;
                } 
                break;
            case 8: if(solveKnightsTour(board, row-1, col+2, move + 1)) {
                    return true;
                } 
                break;
        }
    }

    board[row][col] = EMPTY;

    return false;
}

bool isValid(const vector<vector<int>>& board, int row, int col) {
    
    //check to make sure youre still in the board
    if( row < 0 || row > BOARD_SIZE-1 ) {
        return false;
    }
    if( col < 0 || col > BOARD_SIZE-1 ) {
        return false;
    }

    //check to see if spot has already been moved to
    if( board[row][col] != EMPTY ) {
        return false;
    }

    return true;
}


#endif