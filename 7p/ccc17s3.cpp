#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int f[2001];
int main() {
    cin >> n;
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        f[k]++;
    }
    int ans = 0, height = 0;
    for (int h = 2; h <= 4000; h++) {
        int tot = 0;
        for (int i = 1; i <= h/2; i++) {
            if (h-i > 2000) continue;
            if (i == h-i) {
                tot += f[i]/2;
            }
            else {
                tot += min(f[i], f[h-i]);
            }
        }
        if (tot > height) {
            ans = 1;
            height = tot;
        }
        else if (tot == height) ans++;
    }
    cout << height << " " << ans << "\n";
}
