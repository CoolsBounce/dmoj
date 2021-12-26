#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, r, x, y;
vector<int> adj[200001];
bool vis[200001], vis2[200001];
int dis[200001], pre[200001];
void dfs(int u) {
    vis2[u] = true;
    for (int v : adj[u]) {
        if (!vis2[v]) {
            dfs(v);
            pre[v] = u;
        }
    }
}
int main() {
    cin >> n >> r;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1, k; i <= r; i++) {
        cin >> k; vis[k] =- true; dis[k] = 0; q.push(k);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                dis[t] = dis[cur] + 1;
                q.push(t);
            }
        }
    }
    cin >> x >> y;
    pre[x] = -1;
    dfs(x);
    int ans = INT_MAX;
    for (int n = y; n != -1; n = pre[n]) {
        ans = min(ans, dis[n]);
    }
    cout << ans << "\n";
}
