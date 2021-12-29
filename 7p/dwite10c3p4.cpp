#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char grid[11][11];
bool vis[11][11];
int dis[11][11];
int main() {
    queue<pair<int, int>> q;
    for (int z = 1; z <= 5; z++) {
        for (int i = 1; i <= 10; i++) {
            string s; cin >> s;
            for (int j = 1; j <= 10; j++) {
                grid[i][j] = s[j-1];
                vis[i][j] = false;
                dis[i][j] = 0;
                if (grid[i][j] == 'F') {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto t : adj) {
                pair<int, int> v = {cur.first + t.first, cur.second + t.second};
                if (v.first >= 1 && v.first <= 10 && v.second >= 1 && v.second <= 10) {
                    if (!vis[v.first][v.second] && grid[v.first][v.second] == 'T') {
                        vis[v.first][v.second] = true;
                        dis[v.first][v.second] = dis[cur.first][cur.second] + 1;
                        q.push({v.first, v.second});
                    }
                }
            }
        }
        int max_dis = 0;
        bool flag = true;
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                max_dis = max(max_dis, dis[i][j]);
                if (!vis[i][j] && grid[i][j] == 'T') {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) cout << max_dis << "\n";
        else cout << "-1\n";
        if (z < 5) {
            string a; cin >> a;
        }
    }
}
