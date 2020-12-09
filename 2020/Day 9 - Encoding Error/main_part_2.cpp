#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<long long> vec;
long long invalid = 0, sum = 0, smallest = 0x3f3f3f3f, largest = -0x3f3f3f3f;
pair<int, int> range; // inclusive

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

int findInvalid() {
    for (int i = 25; i < vec.size(); i++) {
        if (noSum(i))
            return i;
    }
    return -1;
}

pair<int, int> findRange() {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += vec[k];
            }
            // if find range, return
            if (sum == invalid)
                return make_pair(i, j);
        }
    }
    // otherwise return
    return make_pair(-1, -1);
}

int main(void) {
    // read input
    readInput();

    // find invalid number
    invalid = vec[findInvalid()];

    // find starting and ending indices of sum
    range = findRange();

    // get smallest and largest
    for (int i = range.first; i <= range.second; i++) {
        // update smallest
        if (vec[i] < smallest)
            smallest = vec[i];
        if (vec[i] > largest)
            largest = vec[i];
    }

    // print answer and exit
    cout << smallest + largest;
    return 0;
}