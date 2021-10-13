#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, l;
vector<string> words;
void recurse(string cur, vector<vector<char>> sets) {
    if (cur.length() >= 1 && cur.length() <= l) {
        words.push_back(cur);
    }
    if (cur.length() < l) {
        for (int i = 0; i < sets.size(); i++) {
            vector<char> curset = sets[i];
            vector<vector<char>> temp(sets.begin() + i+1, sets.end());
            for (char c : curset) {
                cur += c;
                recurse(cur, temp);
                cur = cur.substr(0, cur.length() - 1);
            }
            if (cur.length() == 0) break;
        }
    }
}
int main() {
    cin >> n >> l;
    vector<vector<char>> sets(n);
    for (int i = 0, m; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            sets[i].push_back(c);
        }
    }
    recurse("", sets);
    sort(words.begin(), words.end());
    for (string s : words) cout << s << "\n";
}
