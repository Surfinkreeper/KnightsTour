#include "header.h"

int main() {
    vector<vector<int>> board (BOARD_SIZE, vector<int> (BOARD_SIZE, EMPTY));

    if(!solveKnightsTour(board, 0, 0, 0)) {
        cout << "NOT POSSIBLE" << endl;
    }

    return 0;
}