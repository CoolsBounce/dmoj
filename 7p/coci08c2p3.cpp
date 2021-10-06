#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> ing(n);
    for (int i = 0; i < n; i++) {
        cin >> ing[i].first;
        cin >> ing[i].second;
    }
    int ans = INT_MAX;
    for (int i = 1; i < (1<<n); i++) {
        int sour = 1;
        int bitter = 0;
        for (int j = 0; j < n; j++) {
            if ((1<<j) & i) {
                sour *= ing[j].first;
                bitter += ing[j].second;
            }
        }
        ans = min(ans, abs(sour - bitter));
    }
    cout << ans << "\n";
}
