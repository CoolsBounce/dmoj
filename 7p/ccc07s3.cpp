#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> adj[10000];

int main() {
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int x = -1, y = -1;
    while (x != 0 || y != 0) {
        cin >> x >> y;
        if (x == 0 && y == 0) return 0;
        queue<int> q;
        bool vis[10000];
        int dis[10000];
        for (int i = 1; i <= 9999; i++) {
            vis[i] = false; dis[i] = 0;
        }
        vis[x] = true; dis[x] = -1; q.push(x);
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
        if (!vis[y]) cout << "No\n";
        else cout << "Yes " << dis[y] << "\n";
    }
}
