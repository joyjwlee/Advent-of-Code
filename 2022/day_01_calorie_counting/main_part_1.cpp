#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input file, put into vector
    ifstream file("input.txt");
    vector<string> vals;
    string line;
    while (getline(file, line)) {
        vals.push_back(line);
    }

    // O(n) solve
    int maxSum = 0, sum = 0;
    for (string i : vals) {
        if (i == "") {
            maxSum = max(maxSum, sum);
            sum = 0;
        } else {
            sum += stoi(i);
        }
    }
    maxSum = max(maxSum, sum);
    
    // print and return
    cout << maxSum << endl;
    return 0;
}