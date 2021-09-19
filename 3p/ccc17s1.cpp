#include <bits/stdc++.h>
using namespace std;
int n, t1[100001], t2[100001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t1[i];
    for (int i = 1; i <= n; i++) cin >> t2[i];
    int sum1 = 0, sum2 = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        sum1 += t1[i];
        sum2 += t2[i];
        if (sum1 == sum2) ans = i;
    }
    cout << ans << "\n";
}
