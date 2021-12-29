#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, t;
int ans = INT_MAX;
vector<pair<int, int>> sources;
pair<int, int> init;
char grid[20][20];
int dis[6][20][20];
void bfs(int i) {
    pair<int, int> src = sources[i];
    bool vis[20][20]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) vis[i][j] = false;
    }
    queue<pair<int, int>> q;
    q.push(src);
    vis[src.first][src.second] = true;
    dis[i][src.first][src.second] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto t : adj) {
            pair<int, int> v = {cur.first + t.first, cur.second + t.second};
            if (v.first >= 0 && v.first < n && v.second >= 0 && v.second < m) {
                if (!vis[v.first][v.second] && grid[v.first][v.second] != 'X') {
                    vis[v.first][v.second] = true;
                    dis[i][v.first][v.second] = dis[i][cur.first][cur.second] + 1;
                    q.push({v.first, v.second});   
                }
            }
        }
    }  
}
void generate_perms(vector<int> list, vector<int> cur) {
    if (list.empty()) {
        int curdis = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (i == 0) curdis += dis[0][sources[cur[i]].first][sources[cur[i]].second];
            else curdis += dis[cur[i-1]][sources[cur[i]].first][sources[cur[i]].second];
        }
        ans = min(ans, curdis);
    }
    else {
        int n = list.size();
        for (int i = 0; i < n; i++) {
            cur.push_back(list[i]);
            list.erase(list.begin() + i);
            generate_perms(list, cur);
            list.insert(list.begin() + i, cur[cur.size() - 1]);
            cur.pop_back();
        }
    }
}
int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] == 'G') init = {i, j};
            else if (grid[i][j] == 'H') sources.push_back({i, j});
        }
    }
    sources.insert(sources.begin(), init);
    for (int i = 0; i <= t; i++) bfs(i);
    vector<int> list; for (int i = 1; i <= t; i++) list.push_back(i);
    generate_perms(list, {});
    cout << ans << "\n";
}
