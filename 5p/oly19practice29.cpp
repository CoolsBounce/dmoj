#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[1000];
int main() {
    int x, y, z; cin >> x >> y >> z;
    bool f = false; 
    for (int i = 0; i < 1000; i++) {
        m[i] = x * i;
        if (m[i] % y == z) f = true;
    }
    cout << (f ? "YES\n" : "NO\n");
}
