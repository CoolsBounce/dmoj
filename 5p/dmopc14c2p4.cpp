#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, psa[1000001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    int q; cin >> q;
    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b; a++; b++;
        cout << psa[b] - psa[a-1] << "\n";
    }
}
