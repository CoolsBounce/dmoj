#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int n, q;
vector<int> cnt[2];
int main() {
    cin >> s >> q;
    int n = s.length();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) cnt[i].push_back(0);
    }
    for (int i = 1; i <= n; i++) {
        if (s[i-1] - '0' == 0) {
            cnt[0][i] = 1 + cnt[0][i-1];
            cnt[1][i] = cnt[1][i-1];
        }
        else {
            cnt[0][i] = cnt[0][i-1];
            cnt[1][i] = 1 + cnt[1][i-1];
        }
    }
    for (int i = 0, x, y, z; i < q; i++) {
        cin >> x >> y >> z;
        int target = y + cnt[z][x-1];
        int ind = lower_bound(begin(cnt[z]), end(cnt[z]), target) - begin(cnt[z]);
        cout << (ind <= n ? ind : -1) << "\n";
    }
}
