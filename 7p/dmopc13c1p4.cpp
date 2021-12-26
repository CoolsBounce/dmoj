#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, r, c;
int cx, cy, wx, wy;
void bfs(char grid[51][51], int cx, int cy, int wx, int wy) {
    bool vis[51][51]; int dis[51][51];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            vis[i][j] = false;
            dis[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    vis[cx][cy] = true;
    dis[cx][cy] = 0;
    q.push({cx, cy});
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vector<pair<int, int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto t : adj) {
            pair<int, int> nxt = {cur.first + t.first, cur.second + t.second};
            if (nxt.first >= 1 && nxt.first <= r && nxt.second >= 1 && nxt.second <= c) {
                if (!vis[nxt.first][nxt.second] && grid[nxt.first][nxt.second] != 'X') {
                    vis[nxt.first][nxt.second] = true;
                    dis[nxt.first][nxt.second] = dis[cur.first][cur.second] + 1;
                    q.push({nxt.first, nxt.second});
                }
            }
        }
    }
    if (!vis[wx][wy] || dis[wx][wy] >= 60) cout << "#notworth\n";
    else cout << dis[wx][wy] << "\n";
}
int main() {
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cin >> c >> r;
        char grid[51][51];
        for (int i = 1; i <= r; i++) {
            string s; cin >> s;
            for (int j = 1; j <= c; j++) {
                grid[i][j] = s[j-1];
                if (grid[i][j] == 'C') {
                    cx = i;
                    cy = j;
                }
                else if (grid[i][j] == 'W') {
                    wx = i;
                    wy = j;
                }
            }
        }   
        bfs(grid, cx, cy, wx, wy);
    }
}
