#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<long long> vec;

void readInput() {
    while (getline(file, line)) {
        vec.push_back(stoll(line));
    }
}

bool noSum(int n) {
    for (int i = n - 25; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] + vec[j] == vec[n])
                return false;
        }
    }
    return true;
}

int solve() {
    for (int i = 25; i < vec.size(); i++) {
        if (noSum(i))
            return i;
    }
    return -1;
}

int main(void) {
    // read input
    readInput();

    // solve, print answer, and exit
    cout << vec[solve()];
    return 0;
}