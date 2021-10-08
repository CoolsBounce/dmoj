#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, a[500002], pre[500002], suf[500002], precnt[11][500002], sufcnt[11][500002];
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = max(a[i], pre[i-1]);
        for (int j = 1; j <= 10; j++) {
            if (j == a[i]) precnt[j][i] = 1 + precnt[j][i-1];
            else precnt[j][i] = precnt[j][i-1];
        }
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = max(a[i], suf[i+1]);
        for (int j = 1; j <= 10; j++) {
            if (j == a[i]) sufcnt[j][i] = 1 + sufcnt[j][i+1];
            else sufcnt[j][i] = sufcnt[j][i+1];
        }
    }
    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        int highest = max(pre[a-1], suf[b+1]);
        cout << highest << " " << precnt[highest][a-1] + sufcnt[highest][b+1] << "\n";
    } 
}
