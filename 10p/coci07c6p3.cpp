#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            diff.push_back(a[j] - a[i]);
        }
    }
    int ans = diff[0];
    for (int i = 0; i < diff.size(); i++) {
        ans = gcd(ans, diff[i]);
    }
    for (int i = 2; i*i <= ans; i++) {
        if (ans % i == 0) {
            cout << i << " ";
            if (i != ans/i) cout << ans/i << " ";
        }
    }
    cout << ans << "\n";
}
