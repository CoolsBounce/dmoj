#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> adj[10001];
int dis[10001];
bool vis[10001];
int main() {
    cin >> n;
    for (int i = 1, x, y; i <= n - 1; i++) {
        cin >> x >> y; adj[x].push_back(y); adj[y].push_back(x);
    }
    int id = 0, longest = 0;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                dis[t] = dis[cur] + 1;
                if (dis[t] > longest) {
                    longest = dis[t];
                    id = t;
                }
                q.push(t);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dis[i] = 0; vis[i] = false;
    }
    q.push(id);
    vis[id] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                dis[t] = dis[cur] + 1;
                if (dis[t] > longest) {
                    longest = dis[t];
                    id = t;
                }
                q.push(t);
            }
        }
    }
    cout << longest << "\n";
}
