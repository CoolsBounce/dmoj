#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int z = 0; z < 5; z++) {
        // w[i] and v[i] are weights and value of item i.
        int w[101], v[101]; w[0] = 0; v[0] = 0;
        // dp[i] goes from 1 to the given knapsack size you want to solve for. dp = new int[j + 1];
        int dp[30001]; for (int i = 0; i <= 30000; i++) dp[i] = 0;
        int n, size; cin >> size >> n;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s >> v[i] >> w[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = size; j >= w[i]; j--) {
                dp[j] = max(dp[j], v[i]+dp[j - w[i]]);
            }
        }
        cout << dp[size] << "\n";
        
    }
}
