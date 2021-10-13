#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char a[30][30];
char winner(string s) {
    int cnt = 1;
    char cur = '.';
    for (char c : s) {
        if (c == '.') {
            cnt = 1;
            cur = c;
            continue;
        }
        if (c == cur) {
            cnt++;
            if (cnt == 3) return cur;
        }
        else {
            cnt = 1;
            cur = c;
        }
    }
    return '#';
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        string s = "", t = "";
        for (int j = 0; j < n; j++) {
            s += a[i][j];
            t += a[j][i];
        }
        if (winner(s) != '#') {
            cout << winner(s) << "\n"; return 0;
        }
        if (winner(t) != '#') {
            cout << winner(t) << "\n"; return 0;
        }
    }
    int i = n-1;
    int j = 0;
    while (i != 0 || j != n) {
        string s = ""; 
        for (int x = i, y = j; x < n && y < n; x++, y++) s += a[x][y];
        if (winner(s) != '#') {
            cout << winner(s) << "\n"; return 0;
        }
        if (i > 0) i--;
        else j++;
    }

    i = n-1;
    j = n-1;
    while (i != 0 || j != -1) {
        string s = ""; 
        for (int x = i, y = j; x < n && y >= 0; x++, y--) s += a[x][y];
        if (winner(s) != '#') {
            cout << winner(s) << "\n"; return 0;
        }
        if (i > 0) i--;
        else j--;
    }
    cout << "ongoing\n";
}
