#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
unordered_map<int, unordered_set<int>> x, y;
int main() {
    cin >> n;
    for (int i = 0, x0, y0; i < n; i++) {
        cin >> x0 >> y0; x[x0].insert(y0); y[y0].insert(x0);
    }
    int ans = 0;
    for (int i = -20000; i <= 20000; i++) {
        if (x[i].empty()) continue;
        for (int a : x[i]) {
            for (int b : x[i]) {
                for (int c : y[a]) {
                    if (x[c].find(a) != x[c].end() && x[c].find(b) != x[c].end()) {
                        ans = max(ans, abs((b-a) * (c-i)));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
