#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    for (int z = 0, m; z < n; z++) {
        cin >> m;
        vector<int> nums;
        for (int i = 2; i*i <= m; i++) {
            while (m % i == 0) {
                nums.push_back(i);
                m /= i;
            }
        }
        if (m != 1) nums.push_back(m);
        for (int x : nums) cout << x << " ";
        cout << "\n";
    }
}
