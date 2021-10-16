#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool grid[1001][1001];
int main() {
    int a = 0;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) {
        int temp = x1; x1 = x2; x2 = temp;
    }
    if (y1 > y2) {
        int temp = y1; y1 = y2; y2 = temp;
    }
    int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    if (x3 > x4) {
        int temp = x3; x3 = x4; x4 = temp;
    }
    if (y3 > y4) {
        int temp = y3; y3 = y4; y4 = temp;
    }
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) grid[i][j] = true;
    }
    for (int i = y3; i < y4; i++) {
        for (int j = x3; j < x4; j++) grid[i][j] = true;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) if (grid[i][j]) a++;
    }
    cout << a << "\n";
}
