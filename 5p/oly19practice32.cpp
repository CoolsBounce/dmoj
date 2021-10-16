#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second < b.second);
}

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> r1;
    vector<pair<int, int>> r2;
    for (int i = 1, a; i <= n; i++) {
        cin >> a; r1.push_back(make_pair(i, a));
        cin >> a; r2.push_back(make_pair(i, a));
    }
    sort(r1.begin(), r1.end(), comp);
    vector<pair<int, int>> r3;
    for (int i = r1.size() - 1; i >= r1.size() - k; i--) {
        r3.push_back(make_pair(r1[i].first, r2[r1[i].first - 1].second));
    }
    sort(r3.begin(), r3.end(), comp);
    cout << r3[r3.size() - 1].first << "\n";
}
