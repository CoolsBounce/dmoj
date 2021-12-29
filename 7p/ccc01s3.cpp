#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[26];
vector<pair<char, char>> e, roads;
int ans = 0;
void bfs(pair<char, char> e) {
    bool vis[26]; for (int i = 0; i < 26; i++) vis[i] = false;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int t : adj[cur]) {
            if (!vis[t]) {
                vis[t] = true;
                q.push(t);
            }
        }
    }
    if (!vis[1]) {
        ans++;
        roads.push_back(e);
    }
}
int main() {
    string s = "";
    while (s != "**") {
        cin >> s;
        if (s == "**") break;
        adj[s[0] - 'A'].push_back(s[1] - 'A');
        adj[s[1] - 'A'].push_back(s[0] - 'A');
        e.push_back({s[0], s[1]});
    }
    for (auto edge : e) {
        int a = edge.first - 'A';
        int b = edge.second - 'A';
        adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
        adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
        bfs(edge);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto edge : roads) {
        cout << edge.first << edge.second << "\n";
    }
    cout << "There are " << ans << " disconnecting roads.\n";
}
