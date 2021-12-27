#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, g;
vector<vector<pair<pair<int, int>, int>>> permutations;
void generate_permutations(vector<pair<pair<int, int>, int>> cur) {
    if (cur.size() == 6) {
        permutations.push_back(cur);
        return;
    }
    vector<pair<int, int>> left = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    for (auto x : cur) {
        left.erase(find(left.begin(), left.end(), x.first));
    }
    auto x = left[0];
    cur.push_back({x, -1});
    generate_permutations(cur);
    cur.pop_back();
    cur.push_back({x, 0});
    generate_permutations(cur);
    cur.pop_back();
    cur.push_back({x, 1});
    generate_permutations(cur);
    cur.pop_back();
}
int main() {
    cin >> t >> g;
    vector<pair<pair<int, int>, int>> cur_state;
    for (int i = 1, a, b, sa, sb; i <= g; i++) {
        cin >> a >> b >> sa >> sb;
        int r = 0;
        if (sa > sb) r = 1;
        else if (sa < sb) r = -1;
        cur_state.push_back({{a, b}, r});
    }
    generate_permutations(cur_state);
    int cnt = 0;
    for (int i = 0; i < permutations.size(); i++) {
    }
    for (auto x : permutations) {
        int sc[5];
        for (int i = 1; i <= 4; i++) sc[i] = 0;
        for (auto y : x) {
            if (y.second == 1) sc[y.first.first] += 3;
            else if (y.second == -1) sc[y.first.second] += 3;   
            else {
                sc[y.first.first]++;
                sc[y.first.second]++;
            }
        }
        bool champion = true;
        for (int i = 1; i <= 4; i++) {
            if (i != t && sc[i] >= sc[t]) champion = false;
        }
        if (champion) cnt++;
    }
    cout << cnt << "\n";
}
