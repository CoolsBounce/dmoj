#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int main() {
    cin >> n >> k;
    vector<int> v(n), a(n), f(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; a[i] = v[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        b[i] = lower_bound(a.begin(), a.end(), v[i]) - a.begin();
    }
    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y; x--; y--;
        if (v[x] > v[y]) b[x]--;
        else if (v[y] > v[x]) b[y]--;
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}
