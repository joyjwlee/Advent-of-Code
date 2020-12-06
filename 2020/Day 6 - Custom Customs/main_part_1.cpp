#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input and calculate
    ifstream file("input.txt");
    string line;
    set<char> s;
    int ans = 0;
    while (getline(file, line)) {
        // if we reach end of group, add and reset
        if (line.size() == 0) {
            ans += s.size();
            s.clear();
        } else {
            for (char c : line) {
                s.insert(c);
            }
        }
    }
    ans += s.size(); // don't forget last

    // print ans
    cout << ans;
    return 0;
}