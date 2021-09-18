#include <bits/stdc++.h>
using namespace std;

int main() {
    int h; cin >> h;
    int stars = 1, spaces  = 2*h - 2;
    bool inc = true;
    for (int i = 1; i <= h; i++) {
        string s = "";
        for (int j = 1; j <= stars; j++) {
            s = s + "*";
        }
        for (int j = 1; j <= spaces; j++) {
            s = s + " ";
        }
        for (int j = 1; j <= stars; j++) {
            s = s + "*";
        }
        cout << s << "\n";
        if (stars == h) {
            inc = false;
        }
        if (inc) {
            stars += 2;
            spaces -= 4;
        }
        else {
            stars -= 2;
            spaces += 4;
        }
    }
}
