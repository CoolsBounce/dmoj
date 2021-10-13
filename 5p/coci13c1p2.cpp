#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    int s = n;
    int cnt = 0;
    for (int i = 1; i < m; i++) {
        if ((s*i) % m == 0) cnt++;
    }
    cout << m - 1 - cnt << "\n";
}
