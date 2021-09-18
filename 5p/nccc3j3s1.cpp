#include <bits/stdc++.h>
using namespace std;

int a[26];  
int main() {
    string s; cin >> s;
    for (char c : s) {
        a[c - 'a']++;
    }
    sort(a, a + sizeof(a) / sizeof(a[0]));
    int cnt = 0;
    int ans = 0;
    for (int i = 25; i >= 0; i--) {
        if (a[i] > 0) {
            cnt++;
            if (cnt > 2) ans += a[i];
        }
    }
    cout << ans << "\n";
    
}
