#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        int x, y, z; cin >> x >> y >> z;
        if (2010 - z > 13) cout << "old enough\n";
        else if (2010 - z < 13) cout << "too young\n";
        else {
            if (10 > y) cout << "old enough\n";
            else if (10 < y) cout << "too young\n";
            else {
                if (27 >= x) cout << "old enough\n";
                else cout << "too young\n";
            }
        }
    }
}
