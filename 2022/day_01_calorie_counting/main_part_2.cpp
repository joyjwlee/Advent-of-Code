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

    // get calories and sort
    vector<int> calories;
    int sum = 0;
    for (string i : vals) {
        if (i == "") {
            calories.push_back(sum);
            sum = 0;
        } else {
            sum += stoi(i);
        }
    }
    sort(calories.begin(), calories.end(), greater<int>());
    
    // print and return
    cout << calories[0] + calories[1] + calories[2] << endl;
    return 0;
}