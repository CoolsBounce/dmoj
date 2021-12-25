#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[50] = {{}, {6}, {6}, {4, 5, 6, 15}, {3, 5, 6}, {3, 4, 6}, {1, 2, 3, 4, 5, 7},
{6, 8}, {7, 9}, {8, 10, 12}, {9, 11}, {10, 12}, {9, 11, 13}, {12, 14, 15}, {13}, {3, 13}, {17, 18}, {16, 18}, {16, 17}};

int bfs(int mode, int src, int target) {
    queue<int> q;
    bool vis[50]; 
    int dis[50];
    for (int i = 1; i <= 49; i++) {
        vis[i] = false; dis[i] = -1;
    }
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
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
    if (mode == 0) {
        int cnt = 0;
        for (int i = 1; i <= 49; i++){
            if (dis[i] == 2) cnt++;
        } 
        return cnt;
    }
    else {
        return dis[target];
    }
}
int main() {
    char cmd = ' ';
    while (cmd != 'q') {
        cin >> cmd;
        switch (cmd) {
            case 'i': {
                int x, y; cin >> x >> y;
                if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end()) adj[x].push_back(y);
                if (find(adj[y].begin(), adj[y].end(), x) == adj[y].end()) adj[y].push_back(x);
            }
            break;
            case 'd': {
                int x, y; cin >> x >> y;
                if (find(adj[x].begin(), adj[x].end(), y) != adj[x].end()) remove(adj[x].begin(), adj[x].end(), y);
                if (find(adj[y].begin(), adj[y].end(), x) != adj[y].end()) remove(adj[y].begin(), adj[y].end(), x);
            }
            break;
            case 'n': {
                int x; cin >> x;
                cout << adj[x].size() << "\n";
            }
            break;
            case 'f': {
                int x; cin >> x;
                cout << bfs(0, x, 0) << "\n";
            }
            break;
            case 's': {
                int x, y; cin >> x >> y;
                int res = bfs(1, x, y);
                if (res > 0) cout << res << "\n";
                else cout << "Not connected\n";
            }   
            break;
        }
    }
}
