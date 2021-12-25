#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[1000001];
bool vis[1000001];
int main() {
    int n, m; cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int p, q; cin >> p >> q;
    queue<int> qu; vis[p] = true; qu.push(p);
    while (!qu.empty()) {
        int cur = qu.front(); qu.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                qu.push(t);
            }
        }
    }
    if (vis[q]) {
        cout << "yes\n";
        return 0;
    }
    for (int i = 1; i <= 1000000; i++) vis[i] = false;
    vis[q] = true; qu.push(q);
    while (!qu.empty()) {
        int cur = qu.front(); qu.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                qu.push(t);
            }
        }
    }
    if (vis[p]) {
        cout << "no\n";
        return 0;
    }
    cout << "unknown\n";
}
