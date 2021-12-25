#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000001];
int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i <= m; i++) cin >> a[i];
    int mx = 0; int idx = -1;
    for (int i = 1; i <= m; i++) {
        if (a[i] >= mx) {
            idx = i;
            mx = a[i];
        }
    }
    string ans = "";
    for (int i = 0, j = 1; i < s.length(); i++) {
        if (s[i] == '0') {
            if (j == idx) {
                ans = s.substr(i+1) + s.substr(0, i);
                break;
            }
            else j++;
        }
    }
    string ans2 = "";
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] != '0') ans2 += ans[i];
    }
    cout << ans2 << "\n";
}
