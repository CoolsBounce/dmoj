#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> l, h;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = (n-1)/2; i >= 0; i--) l.push_back(a[i]);
    for (int i = (n-1)/2 + 1; i < n; i++) h.push_back(a[i]);
    for (int i = 0; i < l.size(); i++) {
        cout << l[i] << " ";
        if (i < h.size()) cout << h[i] << " ";
    }
    cout << "\n";
}
