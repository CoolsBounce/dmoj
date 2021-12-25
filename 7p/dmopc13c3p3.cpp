#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, h;
int grid[1501][1501];
bool vis[1501][1501];
int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> grid[i][j];
    }
    queue<pair<int, int>> q;
    vis[1][1] = true;
    q.push({1, 1});
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto t : adj) {
            pair<int, int> nxt = {cur.first + t.first, cur.second + t.second};
            if (nxt.first >= 1 && nxt.first <= n && nxt.second >= 1 && nxt.second <= n) {
                if (round(abs(grid[cur.first][cur.second] - grid[nxt.first][nxt.second]) <= h)) {
                    if (!vis[nxt.first][nxt.second]) {
                        vis[nxt.first][nxt.second] = true;
                        q.push({nxt.first, nxt.second});
                    }
                }
            }
        }
    }
    cout << (vis[n][n] ? "yes\n" : "no\n");
}
