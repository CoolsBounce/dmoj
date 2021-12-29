#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r = 10, c = 9;
string grid[11][10];
int val[11][10];
int main() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
            if (grid[i][j][0] <= '9') val[i][j] = stoi(grid[i][j]);
            else val[i][j] = INT_MAX;
        }
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (val[i][j] != INT_MAX) continue;
                int ans = 0;
                for (int k = 0; k < grid[i][j].length(); k += 3) {
                    int x = grid[i][j][k] - 'A' + 1;
                    int y = grid[i][j][k+1] - '0';
                    if (val[x][y] != INT_MAX) ans += val[x][y];
                    else {
                        ans = INT_MAX;
                        break;
                    }
                }
                if (ans != INT_MAX) {
                    val[i][j] = ans;
                    flag = true;
                }
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (val[i][j] != INT_MAX) cout << val[i][j] << " ";
            else cout << "* ";
        }
        cout << "\n";
    }
}
