#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}
int main() {
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> pre(n+2);
    vector<int> suf(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = gcd(a[i], pre[i-1]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = gcd(a[i], suf[i+1]);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, gcd(pre[i-1], suf[i+1]));
    }
    cout << ans << "\n";
}
