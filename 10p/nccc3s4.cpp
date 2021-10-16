#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; ll mx = 0, sum = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        ll b; cin >> b; sum += b; mx = max(mx, b);
    }
    if (sum % 2 == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << (mx > sum - mx ? "NO\n" : "YES\n");
}
