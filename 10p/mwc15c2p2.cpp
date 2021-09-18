#include <bits/stdc++.h>
using namespace std;

int n, h[(int) 1e6 + 1], ind[(int) 1e6 + 1];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    stack<pair<int, int>> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && stk.top().first <= h[i]) stk.pop();
        ind[i] = stk.empty() ? 1 : stk.top().second;
        stk.push({h[i], i});
    }
    for (int i = 1; i <= n; i++) {
        cout << i - ind[i] << " ";
    }
}
