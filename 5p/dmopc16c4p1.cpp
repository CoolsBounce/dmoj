#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        cout << (__builtin_popcountll(x) == 1 ? "T" : "F") << "\n";
    }
}
