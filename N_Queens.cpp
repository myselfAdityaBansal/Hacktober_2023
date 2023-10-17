#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int N) {
    if (col >= N) {
        return true;  // All queens are successfully placed in th chessboard
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;  // Place the queen
            if (solveNQueens(board, col + 1, N)) {
                return true;  
            }
            board[i][col] = 0;  // Backtrack the queen doesn't lead to a solution
        }
    }

    return false; 
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));  // here im Initializing a NxN chessboard

    if (solveNQueens(board, 0, N)) {
        cout << "Solution found:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for N = " << N << "." << endl;
    }

    return 0;
}
