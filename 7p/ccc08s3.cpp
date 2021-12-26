#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, x, y;
int main() {
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> x >> y;
        char grid[21][21];
        for (int i = 1; i <= x; i++) {
            string s; cin >> s;
            for (int j = 1; j <= y; j++) {
                grid[i][j] = s[j-1];
            }
        }
        queue<pair<int, int>> q; int dis[21][21]; bool vis[21][21];
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                dis[i][j] = 0; vis[i][j] = false;
            }
        }
        q.push({1, 1});
        vis[1][1] = true; dis[1][1] = 1;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            vector<pair<int, int>> adj;
            if (grid[cur.first][cur.second] == '+') {
                adj.push_back({1, 0}); adj.push_back({-1, 0}); adj.push_back({0, 1}); adj.push_back({0, -1});
            }
            else if (grid[cur.first][cur.second] == '-') {
                adj.push_back({0, 1}); adj.push_back({0, -1});
            }
            else if (grid[cur.first][cur.second] == '|') {
                adj.push_back({1, 0}); adj.push_back({-1, 0});
            }
            for (auto t : adj) {
                pair<int, int> nxt = {cur.first + t.first, cur.second + t.second};
                if (nxt.first >= 1 && nxt.first <= x && nxt.second >= 1 && nxt.second <= y) {
                    if (!vis[nxt.first][nxt.second] && grid[nxt.first][nxt.second] != '*') {
                        q.push({nxt.first, nxt.second});
                        vis[nxt.first][nxt.second] = true;
                        dis[nxt.first][nxt.second] = dis[cur.first][cur.second] + 1;
                    }
                }
            }
        }
        if (!vis[x][y]) cout << "-1\n";
        else cout << dis[x][y] << "\n";
    }   
}
