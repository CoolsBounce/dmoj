#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<double> v, ne;
    for (int i = 0, x; i < n; i++) {
        cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n - 1; i++) {
        ne.push_back((v[i + 1] / 2 + v[i] / 2) - (v[i] / 2 + v[i - 1] / 2));
    }
    sort(ne.begin(), ne.end());
    cout << setprecision (1) << fixed << ne[0] << "\n";
}
