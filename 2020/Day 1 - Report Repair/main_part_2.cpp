#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input file, put into vector
    ifstream file("input.txt");
    string content;
    vector<int> vals;
    while (file >> content) {
        vals.push_back(stoi(content));
    }

    // O(n^3) bruteforce
    for (int i = 0; i < vals.size(); i++) {
        for (int j = i + 1; j < vals.size(); j++) {
            for (int k = j + 1; k < vals.size(); k++) {
                if (vals[i] + vals[j] + vals[k] == 2020) {
                    cout << vals[i] * vals[j] * vals[k];
                }
            }
        }
    }
}