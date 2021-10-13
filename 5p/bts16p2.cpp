#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int c; cin >> c;
    vector<string> set;
    for (int i = 0, cmd; i < c; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                string s; cin >> s;
                if (find(set.begin(), set.end(), s) == set.end()) {
                    cout << "true\n";
                    set.push_back(s);
                }
                else cout << "false\n";
            }
            break;
            case 2: {
                string s; cin >> s;
                auto it = find(set.begin(), set.end(), s);
                if (it != set.end()) {
                    cout << "true\n";
                    set.erase(it);
                }
                else cout << "false\n";
            }
            break;
            case 3: {
                string s; cin >> s;
                auto it = find(set.begin(), set.end(), s);
                if (it == set.end()) cout << "-1\n";
                else cout << (it - set.begin()) << "\n";
            }
            break;
            case 4: {
                sort(set.begin(), set.end());
                for (string s : set) cout << s << " ";
                cout << "\n";
            }
            break;
        }
    }
}
