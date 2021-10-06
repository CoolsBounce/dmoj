#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c, d, p, m, g;
int cnt[1000];
int main() {
    cin >> a >> b >> c >> d >> p >> m >> g;
    for (int i = 1; i <= 1000; i += (a+b)) {
        for (int j = i; j < i+a; j++) {
            if (j <= 1000) cnt[j]++;
        }
    }
    for (int i = 1; i <= 1000; i += (c+d)) {
        for (int j = i; j < i+c; j++) {
            if (j <= 1000) cnt[j]++;
        }
    }
    if (cnt[p] == 2) cout << "both\n";
    else if (cnt[p] == 1) cout << "one\n";
    else cout << "none\n";

    if (cnt[m] == 2) cout << "both\n";
    else if (cnt[m] == 1) cout << "one\n";
    else cout << "none\n";

    if (cnt[g] == 2) cout << "both\n";
    else if (cnt[g] == 1) cout << "one\n";
    else cout << "none\n";
}
