#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) return (a.second > b.second);
    return a.first < b.first;
}

int n, f[1001];
vector<pair<int, int>> freq;
int main() {
    cin >> n;
    for (int i = 1, r; i <= n; i++) {cin >> r; f[r]++;}
    for (int i = 1; i <= 1000; i++) {
        if (f[i] > 0) freq.push_back({i, f[i]});
    }
    sort(freq.begin(), freq.end(), comp);
    int highest = freq[0].second;
    int ind = -1;
    vector<int> h, s;
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i].second == highest) h.push_back(freq[i].first);
        else {ind = i; break;}
    }
    if (ind != -1) {
        int secondh = freq[ind].second;
        for (int i = ind; i < freq.size(); i++) {
            if (freq[i].second == secondh) s.push_back(freq[i].first);
            else break;
        }
    }
    if (h.size() > 1) cout << h[h.size() - 1] - h[0] << "\n";
    else {
        int ans = -1;
        for (int k : s) ans = max(ans, abs(k - h[0]));
        cout << ans << "\n";
    }
}
