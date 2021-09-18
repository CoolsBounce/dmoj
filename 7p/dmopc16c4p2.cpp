#include <bits/stdc++.h>
using namespace std;
int b, fails, f[100001], e[100001], p[100001];
int main() {
    int ans = 0;
    cin >> b;
    for (int i = 1; i <= b; i++) {
        cin >> f[i] >> e[i] >> p[i];
    }
    cin >> fails;
    vector<int> fail(fails);
    for (int i = 0; i < fails; i++) {
        cin >> fail[i];
    }
    sort(fail.begin(), fail.end());
    for (int i = 1; i <= b; i++) {
        int ind = lower_bound(fail.begin(), fail.end(), f[i]) - fail.begin();
        if (ind == fails) ans += p[i];
        else if (fail[ind] > e[i]) ans += p[i];
    }
    cout << ans << "\n";
}
