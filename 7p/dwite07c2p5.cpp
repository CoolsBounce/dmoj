#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<pair<int, int>> edges;
vector<int> adj[101];
bool vis[101];
int main() {
    for (int z = 1; z <= 5; z++) {
        cin >> n >> m;
        edges.clear();
        for (int i = 0; i <= 100; i++) adj[i].clear();
        for (int i = 1, a, b; i <= m; i++) {
            cin >> a >> b;
            edges.push_back({a, b});
            adj[a].push_back(b); adj[b].push_back(a);
        }
        int cnt = 0;
        for (auto e : edges) {
            adj[e.first].erase(find(adj[e.first].begin(), adj[e.first].end(), e.second));
            adj[e.second].erase(find(adj[e.second].begin(), adj[e.second].end(), e.first));
            queue<int> q; for (int i = 1; i <= n; i++) vis[i] = false;
            vis[1] = true; q.push(1);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int t : adj[cur]) {
                    if (!vis[t]) {
                        vis[t] = true;
                        q.push(t);
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    cnt++;
                    break;
                }
            }
            adj[e.first].push_back(e.second); adj[e.second].push_back(e.first);
        }
        cout << cnt << "\n";
    }
}
