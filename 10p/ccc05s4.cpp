#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l;
map<string, int> dis;
map<string, bool> vis;
int main() {
    cin >> l;
    for (int z = 1; z <= l; z++) {
        dis.clear();
        vis.clear();
        int n; cin >> n;
        vector<string> lis;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            lis.push_back(s);
        }
        string root = lis[lis.size() - 1];
        int prevtime = lis.size() * 10;
        dis[root] = 0;
        vis[root] = true;
        int maxdis = 0;
        for (int i = 0, pre = 0; i < lis.size(); i++) {
            string cur = lis[i];
            if (!vis[cur]) {
                vis[cur] = true;
                dis[cur] = pre + 1;
                pre++;
                maxdis = max(maxdis, dis[cur]);
            }
            else pre--;
        }
        cout << prevtime - maxdis * 20 << "\n";
    }
}
