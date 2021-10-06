#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime[10000001];
int main() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i*i <= 10000000; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= 10000000; j += i) isPrime[j] = false;
        }
    }
    for (int z = 0, n; z < 5; z++) {
        cin >> n;
        if (isPrime[n]) {
            cout << n << " = " << n << "\n";
            continue;
        }
        bool found = false;
        for (int i = n/2; i >= 3; i--) {
            if (isPrime[i] && isPrime[n-i]) {
                found = true;
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
        if (found) continue;
        for (int i = n/3; i >= 3; i--) {
            if (!isPrime[i]) continue;
            int j = n-i;
            for (int k = j/2; k >= i; k--) {
                if (isPrime[k] && isPrime[j-k]) {
                    found = true;
                    cout << n << " = " << i << " + " << k << " + " << j-k << "\n";
                    break;
                }
            }
            if (found) break;
        }
    }
}
