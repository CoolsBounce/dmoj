#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, s, t;
bool vis[1000001];
int dis[1000001];
vector<int> adj[1000001];
int main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y; 
        adj[x].push_back(y); adj[y].push_back(x);
    }
    cin >> s >> t;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int u : adj[cur]) {
            if (!vis[u]) {
                vis[u] = true;
                dis[u] = dis[cur] + 1;
                q.push(u);
            }
        }
    }
    cout << m - dis[t] << "\n";
}
