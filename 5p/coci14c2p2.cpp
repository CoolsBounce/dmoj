#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    unordered_set<string> s;
    for (int i = 0; i < 2*n-1; i++) {
        string k; cin >> k;
        if (s.find(k) == s.end()) s.insert(k);
        else s.erase(k);
    }
    cout << *s.begin() << "\n";
}
