#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i*i <= x; i++) if (x % i == 0) return false;
    return true;
}
int main() {
    int n; cin >> n;
    while (!isprime(n)) n++;
    cout << n << "\n";
}
