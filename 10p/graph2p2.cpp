#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int adj[1001][1001];
int vis[1001];
bool cycle_exists = false;

void dfs(int u) {
    vis[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1) {
            if (vis[v] == 0) {
                dfs(v);
            }
            else if (vis[v] == 1) {
                cycle_exists = true;
            }
        }
    }
    vis[u] = 2;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> adj[i][j];
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) dfs(i);
    }
    cout << (cycle_exists ? "NO\n" : "YES\n");
}
