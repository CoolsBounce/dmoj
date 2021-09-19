#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m/2) continue;
        int ind = upper_bound(a.begin(), a.end(), m - a[i]) - a.begin();
        ans += ind - i - 1;
    }
    cout << ans << "\n";
}
