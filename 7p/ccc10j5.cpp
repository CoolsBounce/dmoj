#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dis[9][9];
bool vis[9][9];
int main() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int>> q;
    vis[x1][y1] = true;
    dis[x1][y1] = 0;
    q.push({x1, y1});
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vector<pair<int, int>> adj = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        for (auto t : adj) {
            pair<int, int> next = {cur.first + t.first, cur.second + t.second};
            if (next.first >= 1 && next.first <= 8 && next.second >= 1 && next.second <= 8) {
                if (!vis[next.first][next.second]) {
                    vis[next.first][next.second] = true;
                    dis[next.first][next.second] = dis[cur.first][cur.second] + 1;
                    q.push(next);
                }
            }
        }
    }
    cout << dis[x2][y2] << "\n";
}
