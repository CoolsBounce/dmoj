#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char v[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
string last(string s) {
    string word = "";
    for (char c : s) {
        if (c == ' ') word = "";
        else word += c;
    }

    int start = 0;
    for (int i = 0; i < word.length(); i++) {
        if (find(begin(v), end(v), word[i]) != end(v)) {
            start = i;
        }
    }
    return word.substr(start);
}
bool eq(string s1, string s2) {
    string a1 = "";
    string a2 = "";
    for (char x : s1) a1 += tolower(x);
    for (char x : s2) a2 += tolower(x);
    return a1 == a2;
}
int main() {
    int n; cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        vector<string> syl(4);
        for (int j = 0; j < 4; j++) {
            string s; getline(cin, s); syl[j] = last(s);
        }
        if (eq(syl[0], syl[1]) && eq(syl[1], syl[2]) && eq(syl[2], syl[3])) cout << "perfect\n";
        else if (eq(syl[0], syl[1]) && eq(syl[2], syl[3])) cout << "even\n";
        else if (eq(syl[0], syl[2]) && eq(syl[1], syl[3])) cout << "cross\n";
        else if (eq(syl[0], syl[3]) && eq(syl[1], syl[2])) cout << "shell\n";
        else cout << "free\n";
    }
}
