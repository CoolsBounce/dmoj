#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
vector<int> adj[26];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        string s, t; cin >> s >> t;
        adj[s[0] - 'A'].push_back(t[0] - 'A');
        adj[t[0] - 'A'].push_back(s[0] - 'A');
    }
    for (int z = 1; z <= n; z++) {
        string s, t; cin >> s >> t;
        int a = s[0] - 'A';
        int b = t[0] - 'A';
        bool vis[26]; 
        int pre[26];
        for (int i = 0; i < 26; i++) {
            vis[i] = false;
            pre[i] = -1;
        }
        queue<int> q;
        vis[a] = true;
        q.push(a);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int t : adj[cur]) {
                if (!vis[t]) {
                    vis[t] = true;
                    pre[t] = cur;
                    q.push(t);
                }
            }
        }
        stack<int> path;
        for (int u = b; u != -1; u = pre[u]) {
            path.push(u);
        }
        while (!path.empty()) {
            cout << (char) (path.top() + 'A');
            path.pop();
        }
        cout << "\n";
    }
}
