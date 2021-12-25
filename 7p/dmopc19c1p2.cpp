#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll len[31];
int q;
string s0 = "Good writing is good writing is good writing.";
string beg = "Good writing is good ";
string mid = " writing is good ";
string en = " is good writing.";
char recurse(int n, ll k) {
    if (n == 0) return s0[k-1];
    if (k <= beg.length()) return beg[k-1];
    if (k <= beg.length() + len[n-1]) return recurse(n-1, k-beg.length());
    if (k <= beg.length() + len[n-1] + mid.length()) return mid[k - len[n-1] - beg.length() - 1]; 
    if (k <= beg.length() + 2*len[n-1] + mid.length()) return recurse(n-1, k-mid.length()-len[n-1]-beg.length());
    if (k <= beg.length() + 2*len[n-1] + mid.length() + en.length()) return en[k-1-(2*len[n-1]) - beg.length() - mid.length()];
}
int main() {
    len[0] = 45;
    for (int i = 1; i <= 30; i++) {
        len[i] = 2*len[i-1] + 55;
    }
    cin >> q;
    for (int i = 1, n; i <= q; i++) {
        ll k; cin >> n >> k;
        if (k > len[n]) {
            cout << "." << "\n";
            continue;
        }
        cout << recurse(n, k) << "\n";
    }
}
