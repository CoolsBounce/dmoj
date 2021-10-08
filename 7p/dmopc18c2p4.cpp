#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m, dmg[500002];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> dmg[i];
    int ans = INT_MAX;
    int l = 1, r = 1;
    ll tot = dmg[1];
    while (r <= n) {
        // evaluate at l, r
        if (tot >= m) {
            ans = min(ans, r-l+1);
            tot -= dmg[l];
            l++;
        }
        else {
            r++; tot += dmg[r];
        }
        if (l == r) {
            r++; tot += dmg[r];
        }
    }
    cout << (ans != INT_MAX ? ans : -1) << "\n";
}
