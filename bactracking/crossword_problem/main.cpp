#include<bits/stdc++.h>
using namespace std;

#define N 10

char grid[11][11];

void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void solveCrossword(map<int, vector<string>> m, int i, int j) {
    if ((i == N - 1 && j == N - 1) || (i == N && j == 0)) {
        printGrid();
        return;
    }
    if (grid[i][j] != '+') {
        if (j < N - 1 && grid[i][j + 1] == '-') {
            int t = j;
            int count = 0;
            while (t < N && grid[i][t] != '+') {
                count++;
                t++;
            }
            t = j - 1;
            while (t >= 0 && grid[i][t] != '+') {
                count++;
                t--;
            }
            t++;
            for (int k = 0; k < m[count].size(); k++) {
                string s = m[count][k];
                bool flag = true;
                string cache = "";
                for (int l = 0; l < count; l++) {
                    cache += grid[i][l + t];
                    if (grid[i][l + t] != '-' && s[l] != grid[i][l + t]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int l = 0; l < count; l++) {
                        grid[i][l + t] = s[l];
                    }
                    if (t + count == N) {
                    	solveCrossword(m, i + 1, 0);
                    }
                    else solveCrossword(m, i, t + count);
                    for (int l = 0; l < count; l++) {
                        grid[i][l + t] = cache[l];
                    }
                }
            }
        }
        else if (i < N - 1 && grid[i + 1][j] == '-') {
            int t = i;
            int count = 0;
            while (t < N && grid[t][j] != '+') {
                count++;
                t++;
            }
            t = i - 1;
            while (t >= 0 && grid[t][j] != '+') {
                count++;
                t--;
            }
            t++;
            for (int k = 0; k < m[count].size(); k++) {
                string s = m[count][k];
                bool flag = true;
                string cache = "";
                for (int l = 0; l < count; l++) {
                    cache += grid[l + t][j];
                    if (grid[l + t][j] != '-' && s[l] != grid[l + t][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int l = 0; l < count; l++) {
                        grid[l + t][j] = s[l];
                    }
                    if (j + 1 == N) {
                        solveCrossword(m, i + 1, 0);
                    }
                    else solveCrossword(m, i, j + 1);
                    for (int l = 0; l < count; l++) {
                        grid[l + t][j] = cache[l];
                    }
                }
            }
        } else {
            if (j == N - 1) {
                solveCrossword(m, i + 1, 0);
            } else {
                solveCrossword(m, i, j + 1);
            }
        } 
    } else {
        if (j == N - 1) {
            solveCrossword(m, i + 1, 0);
        } else {
            solveCrossword(m, i, j + 1);
        }
    }
}

int main() {
	for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            grid[i][j] = s[j];
        }
    }
    map<int, vector<string>> m;
	string s;
    cin >> s;
    int start = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ';') {
            string sub = s.substr(start, count);
            m[count].push_back(sub);
            start = i + 1;
            count = 0;
        } else {
            count++;
        }
    }
    string sub = s.substr(start, count);
    m[count].push_back(sub);
    solveCrossword(m, 0, 0);
    return 0;
}