#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int rcnt[1001], ccnt[1001];
int main() {
    int r, c; cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'X') {
                rcnt[j+1]++;
                ccnt[i+1]++;
            }
        }
    }
    int q; cin >> q;
    for (int i = 0, x, y; i < q; i++) {
        cin >> x >> y;
        if (rcnt[x] == 0 && ccnt[y] == 0) cout << "N\n";
        else cout << "Y\n";
    }
}
