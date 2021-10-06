#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int psa[500001];
int main() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    for (int j = 0, a, b; j < q; j++) {
        cin >> a >> b;
        cout << psa[n] - (psa[b] - psa[a-1]) << "\n";
    }
}
