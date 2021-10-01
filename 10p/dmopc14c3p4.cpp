#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int factors[100001]; // factors[i] is how many factors an integer i has
vector<int> x[200]; // each a[i] is an array containing all the numbers that contain i factors.
int main() {
    for (int i = 1; i <= 100000; i++) {
        if (i == 1) factors[i] = 1;
        else {
            for (int j = 1; j*j <= i; j++) {
                if (i % j == 0) {
                    if (j*j != i) factors[i] += 2;
                    else factors[i]++;
                }
            }
        }
    }

    for (int i = 1; i <= 100000; i++) x[factors[i]].push_back(i);
    cin >> t;
    for (int i = 0, k, a, b; i < t; i++) {
        cin >> k >> a >> b;
        if (k >= 200) {
            cout << "0\n";
            continue;
        }
        int ans = upper_bound(x[k].begin(), x[k].end(), b) - lower_bound(x[k].begin(), x[k].end(), a);
        cout << ans << "\n";
    }
}
