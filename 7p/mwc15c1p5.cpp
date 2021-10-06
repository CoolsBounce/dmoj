#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod10(int base, int exp) {
    // returns base^exp mod 10
    base %= 10;
    if (exp == 0) return 1;
    if (exp == 1) return base;
    if (exp % 2 == 1) {
        return (base * mod10(base, exp-1)) % 10;
    }
    if (exp % 2 == 0) {
        return ((int) round(pow(mod10(base, exp/2),2))) % 10;
    }
}
int main() {
    string a, b; cin >> a >> b;
    int x = 0, y = 0;
    for (int i = 0; i < a.length(); i++) {
        int base = (tolower(a[i]) - 'a' + 1) % 10;
        x += mod10(base, i+1);
        x %= 10;
    }
    for (int i = 0; i < b.length(); i++) {
        int base = (tolower(b[i]) - 'a' + 1) % 10;
        y += mod10(base, i+1);
        y %= 10;
    }
    if (x == 0) x = 10;
    if (y == 0) y = 10;
    cout << x + y << "\n";
}
