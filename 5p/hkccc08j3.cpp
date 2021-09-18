#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, string> book;
    for (int i = 0; i < n; i++) {
        string s; int k; cin >> s >> k;
        book[k] = s;
    }
    int d; cin >> d;
    unordered_map<int, int> f;

    int max = 0;
    int corresponding = 0;
    for (int i = 0; i < d; i++) {
        int k; cin >> k;
        f[k]++;
        if (f[k] > max) {
            max = f[k];
            corresponding = k;
        }
        else if (f[k] == max) {
            corresponding = min(corresponding, k);
        }
    }
    cout << book[corresponding] << "\n";
}
