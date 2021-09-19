#include <bits/stdc++.h>
using namespace std;
char grid[8][8];

int recurse(int x, int y) {
    int val;
    if (grid[x][y] == '.' || grid[x][y] == '#') val = 0;
    else val = grid[x][y] - '0';
    if (x == 0 && y == 0) return val;
    if (grid[x][y] == '#') return val;
    return val + max(x > 0 ? recurse(x-1, y) : 0, y > 0 ? recurse(x, y-1) : 0);
}

int main() {
    for (int z = 1; z <= 5; z++) {
        for (int i = 7; i >= 0; i--) {
            string s; cin >> s;
            for (int j = 0; j < 8; j++) grid[i][j] = s[j];
        }
        cout << recurse(7, 7) << "\n";
        string s; cin >> s;
    }
}
