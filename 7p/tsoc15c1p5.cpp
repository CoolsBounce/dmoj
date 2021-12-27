#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, w;
bool vis_a[101], vis[101];
int dis_a[101], dis[101];
vector<int> adj[101];
int main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    cin >> w;
    queue<int> q;
    for (int i = 1, a; i <= w; i++) {
        cin >> a;
        vis_a[a] = true;
        dis_a[a] = 0;
        q.push(a);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis_a[t]) {
                vis_a[t] = true;
                dis_a[t] = dis_a[cur] + 4;
                q.push(t);
            }
        }
    }
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis[t] && dis[cur] + 1 < dis_a[t]) {
                vis[t] = true;
                dis[t] = dis[cur] + 1;
                q.push(t);
            }
        }
    }
    if (vis[n]) cout << dis[n] << "\n";
    else cout << "sacrifice bobhob314\n";
}
