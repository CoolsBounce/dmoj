#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int z = 1; z <= 5; z++) {
        string s; cin >> s;
        int largest = 0;
        for (char c : s) {
            largest = max(largest, c - '0');
        }
        cout << largest << "\n";
    }
}
