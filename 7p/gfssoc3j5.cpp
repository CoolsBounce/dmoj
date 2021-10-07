#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> p;
int fun(int pos, vector<int> rem) {
    if (rem.size() == 1) return (abs(pos - p[rem[0]].first) + 1) * p[rem[0]].second;
    int totw = 0;
    int ans = INT_MAX;
    for (int a : rem) totw += p[a].second;
    for (int i = 0; i < rem.size(); i++) {
        int old = rem[i];
        int len = abs(pos - p[rem[i]].first) + 1;
        int newpos = p[rem[i]].first;
        rem.erase(rem.begin() + i);
        ans = min(ans, (len * totw) + fun(newpos, rem));
        rem.insert(rem.begin() + i, old);
    }
    return ans;
}
int main() {
    cin >> n;
    vector<int> rem;
    for (int i = 0, z, w; i < n; i++) {
        cin >> z >> w;
        p.push_back({z, w});
        rem.push_back(i);
    }
    int ans = fun(101, rem); cout << ans << "\n";
}
