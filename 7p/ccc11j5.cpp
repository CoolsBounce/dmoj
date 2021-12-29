#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ans = 0;
bool valid = true;
vector<int> adj[7];
void dfs(int u, int i) {
    for (int v : adj[u]) {
        if (!(i & (1 << v-1))) valid = false;
        else dfs(v, i);
    }
}
int main() {
    cin >> n;
    for (int i = 1, p; i < n; i++) {
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 0; i < (1 << (n-1)); i++) {
        valid = true;
        for (int j = 1; j < n; j++) {
            if (i & (1 << (j-1))) {
                dfs(j, i);
            }
        }
        if (valid) ans++;
    }
    cout << ans << "\n";
}
