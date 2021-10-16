#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> nums;
int main() {
    ll n; cin >> n;
    for (int i = 1; i <= to_string(n).length(); i++) {
        for (int j = 0; j < 1 << i; j++) {
            string s = "";
            for (int k = 0; k < i; k++) {
                if (j & 1 << k) s = "3" + s;
                else s = "2" + s;
            }
            nums.push_back(stoll(s));
        }
    }
    cout << upper_bound(nums.begin(), nums.end(), n) - nums.begin();
}
