#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> adj[51];
bool vis[51];
vector<pair<int, int>> e;
void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, s, t; i <= m; i++) {
        cin >> s >> t;
        adj[s].push_back(t);
        e.push_back({s, t});
    }
    for (auto edge : e) {
        adj[edge.first].erase(find(adj[edge.first].begin(), adj[edge.first].end(), edge.second));
        for (int i = 1; i <= n; i++) vis[i] = false;
        dfs(1);
        cout << (vis[n] ? "YES\n" : "NO\n");
        adj[edge.first].push_back(edge.second);
    }
}
