#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, t, q;
int dis[1001][1001];
bool vis[1001][1001];
vector<int> adj[1001];
int main() {
    cin >> n >> m >> t;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b; adj[a].push_back(b);
    }
    for (int src = 1; src <= n; src++) {
        queue<int> q;
        vis[src][src] = true;
        q.push(src);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int t : adj[cur]) {
                if (!vis[src][t]) {
                    vis[src][t] = true;
                    dis[src][t] = dis[src][cur] + 1;
                    q.push(t);
                }
            }
        }
    }
    cin >> q;
    for (int i = 1, a, b; i <= q; i++) {
        cin >> a >> b;
        if (vis[a][b]) cout << t*dis[a][b] << "\n";
        else cout << "Not enough hallways!\n";
    }
}
