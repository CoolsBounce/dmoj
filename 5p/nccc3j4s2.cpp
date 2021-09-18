#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> medians;
    for (int z = 0; z < n; z++) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        medians.push_back(a[(n-1)/2]);
    }
    sort(medians.begin(), medians.end());
    cout << medians[(n-1)/2] << "\n";
}
