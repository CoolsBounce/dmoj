#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isWord(string s);
bool isAWord(string s) {
    if (s == "A") return true;
    if ((s[0] == 'B') && (s[s.length() - 1] == 'S') && (isWord(s.substr(1, s.length() - 2)))) return true;
    return false;
}
bool isWord(string s) {
    if (isAWord(s)) return true;
    vector<int>inds;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'N') inds.push_back(i);
    }
    if (inds.empty()) return false;
    for (int ind : inds) {
        if (isAWord(s.substr(0, ind)) && isWord(s.substr(ind+1))) return true;
    }
    return false;
}
int main() {
    string s = "";
    while (s != "X") {
        cin >> s;
        if (s == "X") break;
        cout << (isWord(s) ? "YES\n" : "NO\n"); 
    }
}
