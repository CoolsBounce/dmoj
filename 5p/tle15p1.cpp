#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    return (a.second > b.second);
}

int main() {
    int n, p; cin >> n >> p;
    vector<pair<string, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0, k; j < n; j++) {
            cin >> k;
            a[j].second += k;
        }
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++) {
        cout << i+3 << ". " + a[i].first << "\n";
    }
}
