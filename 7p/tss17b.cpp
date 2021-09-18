#include <bits/stdc++.h>
using namespace std;

int f[1414215];
int main() {
    int n, q; cin >> n >> q;    
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y; int dist = ceil(sqrt(pow(x, 2) + pow(y, 2)));
        f[dist]++;
    }
    for (int i = 1; i <= 1414214; i++) f[i] += f[i - 1];
    for (int i = 0, r; i < q; i++) {
        cin >> r;
        cout << f[r] << "\n";
    }
}
