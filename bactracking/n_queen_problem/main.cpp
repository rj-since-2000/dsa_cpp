#include <bits/stdc++.h>

int board[11][11];

void print(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
    }
    cout << endl;
}

void rec(int n, int row) {
    if (row == n + 1) {
        print(n);
        return;
    }
	for (int i = 1; i <= n; i++) {
        bool isValidPosition = true;
        for (int j = row - 1; j >= 1; j--) {
            if (board[j][i] == 1) {
                isValidPosition = false;
                break;
            }
        }
        if (!isValidPosition) continue;
        int c = i - 1;
        for (int j = row - 1; j >= 1 && c >= 1; j--) {
            if (board[j][c] == 1) {
                isValidPosition = false;
                break;
            }
            c--;
        }
        if (!isValidPosition) continue;
        c = i + 1;
        for (int j = row - 1; j >= 1 && c <= n; j--) {
            if (board[j][c] == 1) {
                isValidPosition = false;
                break;
            }
            c++;
        }
        if (!isValidPosition) continue;
        board[row][i] = 1;
        rec(n, row + 1);
        board[row][i] = 0;
    }
}

void placeNQueens(int n){
    memset(board, 0, sizeof board);
    rec(n, 1);
}
