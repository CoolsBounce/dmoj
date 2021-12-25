#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int n; cin >> n;
    ll g = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        g = gcd(g, a);
    }
    // factorize g
    ll ans = 0;
    if (g == 1) cout << "DNE\n";
    else {
        for (ll y = 2; y*y <= g; y++) {
            while (g % y == 0) {
                g /= y;
                ans = y;
            }
        }
        if (g != 1) ans = max(ans, g);
        cout << ans << "\n";
    }
}
