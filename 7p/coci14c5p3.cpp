#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
map<int, int> h, v, d, d2;
int main() {
    cin >> n >> k;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        h[x]++;
        v[y]++;
        d[x-y]++;
        d2[x+y]++;
        if (h[x] == k || v[y] == k || d[x-y] == k || d2[x+y] == k) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}
