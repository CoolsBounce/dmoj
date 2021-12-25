#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> adj[10001];
bool vis[10001]; int dis[10001];
int k = INT_MAX;
int main() {
    cin >> n;
    for (int i = 1, m; i <= n; i++) {
        cin >> m;
        for (int j = 1, k; j <= m; j++) {
            cin >> k; adj[i].push_back(k);
        }
    }

    queue<int> q;
    vis[1] = true;
    dis[1] = 1;
    q.push(1);
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
    bool visited_all = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) visited_all = false;
    }
    cout << (visited_all ? "Y\n" : "N\n");
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 0 && vis[i]) {
            k = min(k, dis[i]);
        }
    }
    cout << k << "\n";
}
