#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int primacity[10000001];
int n = 10000000;

vector<int> nums[20];
int main() {
    for (int i = 2; i <= n; i++) {
        if (primacity[i] == 0) {
            for (int j = i; j <= n; j += i) primacity[j]++;
        }
    }
    for (int i = 2; i <= n; i++) nums[primacity[i]].push_back(i);
    int t; cin >> t;
    for (int i = 1, a, b, k; i <= t; i++) {
        cin >> a >> b >> k;
        int ans = upper_bound(nums[k].begin(), nums[k].end(), b) - lower_bound(nums[k].begin(), nums[k].end(), a);
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
