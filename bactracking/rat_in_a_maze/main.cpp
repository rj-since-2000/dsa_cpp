#include <string.h>

int path[11][11];

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[i][j] << " ";
        }
    }
    cout << endl;
    return;
}

void solve(int maze[][20], int n, int i, int j) {
    if (i == n - 1 && j == n - 1) {
        print(n);
        return;
    }
    if (maze[i][j] == 0) return;
    if (j < n - 1 && path[i][j + 1] != 1) {
        path[i][j + 1] = 1;
        solve(maze, n, i, j + 1);
        path[i][j + 1] = 0;
    }
    if (i < n - 1 && path[i + 1][j] != 1) {
        path[i + 1][j] = 1;
        solve(maze, n, i + 1, j);
        path[i + 1][j] = 0;
    }
    if (j > 0 && path[i][j - 1] != 1) {
        path[i][j - 1] = 1;
        solve(maze, n, i, j - 1);
        path[i][j - 1] = 0;
    }
    if (i > 0 && path[i - 1][j] != 1) {
        path[i - 1][j] = 1;
        solve(maze, n, i - 1, j);
        path[i - 1][j] = 0;
    }
    return;
}

void ratInAMaze(int maze[][20], int n) {
    memset(path, 0, sizeof path);
    path[0][0] = 1;
	solve(maze, n, 0, 0);
    return;
}
