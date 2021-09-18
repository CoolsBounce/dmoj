#include <bits/stdc++.h>
using namespace std;

int n;
int grid[501][501];
bool vis[501][501];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    queue<pair<int, int>> q;
    vis[1][1] = true;
    q.push({1, 1});
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto t : dir) {
            if (cur.first + t.first >= 1 && cur.first + t.first <= n && cur.second + t.second >= 1 && cur.second + t.second <= n) {
                if (!vis[cur.first + t.first][cur.second + t.second] && grid[cur.first + t.first][cur.second + t.second] == 0) {
                    vis[cur.first + t.first][cur.second + t.second] = true;
                    q.push({cur.first + t.first, cur.second + t.second});
                }
            }
        }
    }
    cout << (vis[n][n] ? "yes\n" : "no\n");

}
