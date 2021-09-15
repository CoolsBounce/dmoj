#include <bits/stdc++.h>
using namespace std;

unordered_set<int> nums;

bool f(int n) {
    for (int i = 0; i <= 1000; i++) {
        if (nums.find(n - i*i) != nums.end()) return true;
        return false;
    }
}
int main() {
    for (int i = 0; i <= 1000; i++) {
        nums.insert(i*i);
    }
}
