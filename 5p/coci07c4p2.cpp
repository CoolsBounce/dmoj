#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool same(int x, int y) {
    string a = to_string(x);
    string b = to_string(y);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
int main() {
    int x; cin >> x;
    int y = x+1;
    bool flag = false;
    while (!same(x, y)) {
        y++;
        if (y > (int) 1e6) {
            flag = true;
            break;
        }
    }
    cout << (flag ? 0 : y) << "\n";
}
