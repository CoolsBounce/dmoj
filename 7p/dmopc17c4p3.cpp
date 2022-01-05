#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, id1;
ll ans;
ll dis[100001], dis1[100001];
bool vis[100001];
vector<pair<int, int>> adj[100001];
void bfs(int src) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 0; vis[i] = false;
    }
    queue<int> q;
    vis[src] = true;
    q.push(src);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto v : adj[cur]) {
            if (!vis[v.first]) {
                vis[v.first] = true;
                dis[v.first] = dis[cur] + v.second;
                q.push(v.first);
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    bfs(1);
    ll mx = 0, id = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > mx) {
            mx = dis[i];
            id = i;
        }
    }
    bfs(id); id1 = id;
    for (int i = 1; i <= n; i++) {
        dis1[i] = dis[i];
    }
    mx = 0; id = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > mx) {
            mx = dis[i];
            id = i;
        }
    }
    bfs(id);
    for (int i = 1; i <= n; i++) {
        if (i != id && i != id1) ans = max(ans, max(dis[i], dis1[i]));
    }
    cout << ans << "\n";
}
