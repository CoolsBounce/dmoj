#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, m;
deque<string> dq;
int main() {
    cin >> t >> m;
    for (int i = 0; i < t; i++) {
        string p, c; cin >> p >> c;
        if (c == "in") dq.push_back(p);
        else if (c == "out") {
            if (dq.back() == p) dq.pop_back();
            else if (dq.front() == p && m >= 1) {
                dq.pop_front(); m--;
            }
        }
    }
    for (string s : dq) cout << s << "\n";
}
