#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int h = 0, v = 0;
    for (char c : s) {
        if (c == 'H') h++;
        else v++;
    }
    h = h % 2;
    v = v % 2;
    int a[2][2] = {{1, 2},{3, 4}};
    if (h > 0) {
        int tmp = a[0][0];
        a[0][0] = a[1][0];
        a[1][0] = tmp;
        tmp = a[0][1];
        a[0][1] = a[1][1];
        a[1][1] = tmp;
    }
    if (v > 0) {
        int tmp = a[0][0];
        a[0][0] = a[0][1];
        a[0][1] = tmp;
        tmp = a[1][0];
        a[1][0] = a[1][1];
        a[1][1] = tmp;
    }
    cout << a[0][0] << " " << a[0][1] << "\n";
    cout << a[1][0] << " " << a[1][1] << "\n";
}
