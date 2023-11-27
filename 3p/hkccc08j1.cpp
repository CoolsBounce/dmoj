#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n; cin >> c;
    int cmax = 0, nmax = 0;
    for (int i = 0, a, b; i < c; i++) {
        cin >> a >> b;
        cmax = max(cmax, a*b);
    }
    cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        nmax = max(nmax, a*b);
    }
    if (cmax > nmax) cout << "Casper\n";
    else if (nmax > cmax) cout << "Natalie\n";
    else cout << "Tie\n";
}
