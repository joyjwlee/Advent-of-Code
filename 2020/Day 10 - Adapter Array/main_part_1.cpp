#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<int> vec;

void readInput() {
    while (getline(file, line)) {
        vec.push_back(stoi(line));
    }
}

int solve() {
    int diff1 = 0, diff3 = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] - vec[i - 1] == 1)
            diff1++;
        if (vec[i] - vec[i - 1] == 3)
            diff3++;
    }
    diff1++, diff3++;
    return diff1 * diff3;
}

int main(void) {
    // read input and sort
    readInput();
    sort(vec.begin(), vec.end());

    // solve, print answer, and exit
    cout << solve();
    return 0;
}