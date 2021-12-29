#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, c, ans;
char grid[36][51]; bool vis[36][51];
int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        string s; cin >> s;
        for (int j = 1; j <= c; j++) grid[i][j] = s[j-1];
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!vis[i][j] && grid[i][j] != '#') {
                bool found = false;
                if (grid[i][j] == 'M') found = true;
                vis[i][j] = true;
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for (auto t : adj) {
                        pair<int, int> v = {cur.first + t.first, cur.second + t.second};
                        if (v.first >= 1 && v.first <= r && v.second >= 1 && v.second <= c) {
                            if (!vis[v.first][v.second] && grid[v.first][v.second] != '#') {
                                vis[v.first][v.second] = true;
                                q.push({v.first, v.second});
                                if (grid[v.first][v.second] == 'M') found = true;
                            }
                        }
                    }
                }
                if (found) ans++;
            }
        }
    }
    cout << ans << "\n";
    
}
