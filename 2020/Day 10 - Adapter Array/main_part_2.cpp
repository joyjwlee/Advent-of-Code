#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<long long> vec;
map<long long, long long> dp;

void readInput() {
    while (getline(file, line)) {
        vec.push_back(stoi(line));
    }
}

long long solve() {
    // add final target
    vec.push_back(vec[vec.size() - 1] + 3);

    // dp through, O(n); dp[i] is # of ways with adapter at jolt i
    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;

    // dp and return
    for (long long i = 3; i < vec.size(); i++)
        dp[vec[i]] = dp[vec[i] - 1] + dp[vec[i] - 2] + dp[vec[i] - 3];
    return dp[vec[vec.size() - 1]];
}

int main(void) {
    // read input and sort
    readInput();
    sort(vec.begin(), vec.end());

    // solve, print answer, and exit
    cout << solve();
    return 0;
}