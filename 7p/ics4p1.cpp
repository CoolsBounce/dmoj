#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void recurse(string cur, vector<char> s) {
    if (s.empty()) {
        cout << cur << "\n";
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        char nxt = s[i]; cur += s[i];
        s.erase(s.begin() + i);
        recurse(cur, s);
        s.insert(s.begin()+i, nxt);
        cur = cur.substr(0, cur.length()-1);
    }
}

int main() {
    string a; cin >> a;
    vector<char> s;
    for (char c : a) s.push_back(c);
    sort(s.begin(), s.end());
    recurse("", s);
}
