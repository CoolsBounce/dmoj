#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b;
vector<int> adj[2001]; bool vis[2001];
int main() {
    cin >> n >> m >> a >> b;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    vis[a] = true;
    q.push(a);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                q.push(t);
            }
        }
    }
    if (vis[b]) cout << "GO SHAHIR!\n";
    else cout << "NO SHAHIR!\n";
}
