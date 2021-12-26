#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int h, v;
int a[1501], b[1501];
map<int, int> x, y;
int main() {
    cin >> h >> v;
    if (h <= 1 || v <= 1) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= h; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= v; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= h-1; i++) {
        for (int j = i+1; j <= h; j++) x[a[j] - a[i]]++;
    }
    for (int i = 1; i <= v-1; i++) {
        for (int j = i+1; j <= v; j++) y[b[j] - b[i]]++;
    }
    
    ll ans = 0;
    auto itx = x.begin();
    auto ity = y.begin();

    while (itx != x.end() && ity != y.end()) {
        if ((*itx).first == (*ity).first) {
            ans += ((*itx).second) * ((*ity).second);
            itx++;
            ity++;
        }
        else if ((*itx).first < (*ity).first) {
            itx++;
        }
        else {
            ity++;
        }
    }
    cout << ans << "\n";
}
