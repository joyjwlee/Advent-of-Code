#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
vector<string> expressions;
int ans = 0;
queue<int> nums;
queue<char> ops;

void readInput() {
    while (getline(file, line)) {
        expressions.push_back(line);
    }
}

int calculate(string s) {
    //
}

void solve() {
    for (string s : expressions)
        ans += calculate(s);
}

int main(void) {
    // read input
    readInput();

    // solve, print answer, and return
    solve();
    cout << ans;
    return 0;
}