#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ii, n, atk[100002];
int main() {
    cin >> ii >> n;
    int j; cin >> j;
    for (int i = 0, xi, xf, k; i < j; i++) {
        cin >> xi >> xf >> k;
        atk[xi] += k;
        atk[xf+1] -= k;
    }
    int ans = 0;
    for (int i = 0; i < ii; i++) {
        atk[i] += atk[i-1];
        if (atk[i] < n) ans++;
    }
    cout << ans << "\n";
}
