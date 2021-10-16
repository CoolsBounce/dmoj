#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; sum += a[i];
    }
    sort(a.begin(), a.end());
    if (a[n-1] >= sum - a[n-1]) cout << sum - a[n-1] << "\n";
    else cout << sum/2 << "\n";
}
