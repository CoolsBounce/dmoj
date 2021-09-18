#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int z = 0; z < 10; z++) {
        int n; cin >> n;
        unordered_set<string> emails;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            string t = "";
            bool at = false;
            bool plus = false;
            for (char c : s) {
                c = tolower(c);
                if (at) {
                    t = t + c;
                }
                else {
                    if (c == '@') {
                        t = t + c;
                        at = true;
                    }
                    else {
                        if (c == '+') {
                            plus = true;
                        }
                        else {
                            if (c != '.') {
                                if (!plus) t = t+c;
                            }
                        }
                    }
                }
            }
            emails.insert(t);
        }
        cout << emails.size() << "\n";
    }
}
