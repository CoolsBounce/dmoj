#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 100001;
int n, m;
ll tree[mx], f[mx], ftree[mx];

ll query(int idx, bool freq) {
    if (!freq) {
        ll sum = 0;
        for (; idx > 0; idx -= (idx & -idx)) sum += tree[idx];
        return sum;
    }
    else {
        int sum = 0;
        for (; idx > 0; idx -= (idx & -idx)) sum += ftree[idx];
        return sum;
    }
}
void update(int idx, ll val, bool freq) {
    if (!freq) {
        for (; idx <= mx; idx += (idx & -idx)) tree[idx] += val;
    }
    else {
        for (; idx <= mx; idx += (idx & -idx)) ftree[idx] += val;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, cur; i <= n; i++) {
        cin >> cur;
        update(i, cur, false);
        f[cur]++;
    }
    for (int i = 1; i <= mx; i++) {
        update(i, f[i], true);
    }
    for (int i = 1; i <= m; i++) {
        char c; cin >> c;
        if (c == 'C') {
            int x, v; cin >> x >> v;
            int before = query(x, false) - query(x - 1, false);
            int after = v;
            update(before, -1, true);
            update(after, 1, true);
            update(x, after - before, false);
        }
        else if (c == 'S') {
            int l, r; cin >> l >> r;
            cout << (query(r, false) - query(l - 1, false)) << "\n";
        }
        else {
            int v; cin >> v;
            cout << query(v, true) << "\n";
        }
    }
}
