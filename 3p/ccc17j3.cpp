#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, d, t; cin >> a >> b >> c >> d >> t;
    if (abs(a-c) + abs(b-d) > t) cout << "N\n";
    else {
        cout << (((t - (abs(a-c) + abs(b-d))) % 2 == 0) ? "Y\n" : "N\n");
    }
}
