#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, nums[1000001];
unordered_map<int, int> cur;
int main() {
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    int l = 1, r = 1;
    cur[nums[1]] = 1;
    while (r <= n) {
        if (cur.size() < k) {
            r++;
            cur[nums[r]]++;
        }
        else {
            ans += n - r + 1;
            cur[nums[l]]--;
            if (cur[nums[l]] == 0) cur.erase(nums[l]);
            l++;
            if (l > r) {
                r = l;
                cur[nums[r]]++;
            }
        }
    }
    cout << ans << "\n";
}
