#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    double ans = ((double) x / (double) y) * 1000;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ans = min(ans, ((double) a / (double) b) * 1000);
    }
    cout << ans << "\n";
}
