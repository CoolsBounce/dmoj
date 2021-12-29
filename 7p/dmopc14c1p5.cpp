#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, c, t, rstart, cstart, rgoal, cgoal, d1, d2;
char grid[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];
int main() {
    cin >> r >> c >> rstart >> cstart >> rgoal >> cgoal;
    rstart++; cstart++; rgoal++; cgoal++;
    for (int i = 1; i <= r; i++) {
        string s; cin >> s;
        for (int j = 1; j <= c; j++) grid[i][j] = s[j-1];
    }
    cin >> t;
    vector<pair<int, int>> tp;
    for (int i = 1, a, b; i <= t; i++) {
        cin >> a >> b; a++; b++;
        tp.push_back({a, b});
    }
    queue<pair<int, int>> q;
    q.push({rstart, cstart});
    vis[rstart][cstart] = true;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto t : adj) {
            pair<int, int> v = {cur.first + t.first, cur.second + t.second};
            if (v.first >= 1 && v.first <= r && v.second >= 1 && v.second <= c) {
                if (!vis[v.first][v.second] && grid[v.first][v.second] == 'O') {
                    vis[v.first][v.second] = true;
                    dis[v.first][v.second] = dis[cur.first][cur.second] + 1;
                    q.push({v.first, v.second});
                }
            }
        }
    }
    int d1 = dis[rgoal][cgoal];
    for (auto t : tp) grid[t.first][t.second] = 'T';
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            vis[i][j] = false; dis[i][j] = 0;
        }
    }
    q.push({rstart, cstart});
    vis[rstart][cstart] = true;
    while (!q.empty()) {
        if (d2 != 0) break;
        auto cur = q.front(); q.pop();
        vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto t : adj) {
            pair<int, int> v = {cur.first + t.first, cur.second + t.second};
            if (v.first >= 1 && v.first <= r && v.second >= 1 && v.second <= c) {
                if (!vis[v.first][v.second] && (grid[v.first][v.second] == 'O' || grid[v.first][v.second] == 'T')) {
                    vis[v.first][v.second] = true;
                    dis[v.first][v.second] = dis[cur.first][cur.second] + 1;
                    if (grid[v.first][v.second] == 'T') {
                        d2 = dis[v.first][v.second];
                        break;
                    }
                    q.push({v.first, v.second});
                }
            }
        }
    }
    cout << d1 - d2 << "\n";
}
