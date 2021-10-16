#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, f[10000001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        f[a]++;
        f[b]--;
    }
    int ans = 0;
    for (int i = 1; i <= 10000000; i++) {
        f[i] = f[i - 1] + f[i];
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";
}
