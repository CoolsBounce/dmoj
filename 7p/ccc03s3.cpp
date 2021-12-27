#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char grid[26][26];
bool vis[26][26];
int rmnum[26][26];
int main() {
    int a, r, c; cin >> a >> r >> c;
    for (int i = 1; i <= r; i++) {
        string s; cin >> s;
        for (int j = 1; j <= c; j++) grid[i][j] = s[j-1];
    }
    vector<int> rmsize;
    rmsize.push_back(0);
    int room = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if ((grid[i][j] == '.') && (!vis[i][j])) {
                vis[i][j] = true;
                rmnum[i][j] = room;
                rmsize.push_back(1);
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for (auto t : adj) {
                        pair<int, int> nxt = {cur.first + t.first, cur.second + t.second};
                        if ((nxt.first >= 1) && (nxt.first <= r) && (nxt.second >= 1) && (nxt.second <= c)) {
                            if ((!vis[nxt.first][nxt.second]) && (grid[nxt.first][nxt.second] != 'I')) {
                                vis[nxt.first][nxt.second] = true;
                                q.push({nxt.first, nxt.second});
                                rmnum[nxt.first][nxt.second] = room;
                                rmsize[room]++;
                            }
                        }
                    }
                }
                room++;
            }
        }
    }
    sort(rmsize.begin(), rmsize.end());
    int f = 0;
    for (int i = rmsize.size() - 1; i >= 1; i--) {
        if (a >= rmsize[i]) {
            a -= rmsize[i];
            f++;
        }
        else break;
    }
    if (f == 1) cout << f << " room, " << a << " square metre(s) left over\n";
    else cout << f << " rooms, " << a << " square metre(s) left over\n";
}
