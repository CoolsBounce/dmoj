#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> lis;
int n;
int total = 0;
void printlist() {
    cout << n << "=";
    for (int i = 0; i < lis.size()-1; i++) cout << lis[i] << "+";
    cout << lis[lis.size()-1] << "\n";
}
void recurse(int k) {
    if (k == 0) {
        if (lis.size() > 1) {
            printlist();
            total++;
        }
    }
    int startat = (lis.empty() ? 1 : lis[lis.size() - 1]);
    for (int i = startat; i <= k; i++) {
        lis.push_back(i);
        recurse(k-i);
        lis.pop_back();
    }
}
int main() {
    cin >> n;
    if (n == 1) cout << "total=0\n";
    else if (n == 2) {
        cout << "2=1+1\n";
        cout << "total=1\n";
    }
    else if (n == 3) {
        cout << "3=1+1+1\n";
        cout << "3=1+2\n";
        cout << "total=2\n";
    }
    else {
        recurse(n);
        cout << "total=" << total << "\n";
    }
}
