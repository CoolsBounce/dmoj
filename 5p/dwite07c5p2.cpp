#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int z = 0, n; z < 5; z++) {
        cin >> n;
        int ans = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            while (n % i == 0) {
                ans++;
                n /= i;
            }
        }
        if (n != 1) ans++;
        cout << (ans > 1 ? ans : 0) << "\n";
    }
}
