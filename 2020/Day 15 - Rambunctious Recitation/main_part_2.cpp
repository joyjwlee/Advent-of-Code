#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
vector<int> vec;
size_t pos;
string delim = ",", token;
map<int, vector<int>> mp;
int idx = 1, last;

void readInput() {
    while (getline(file, line)) {
        // split by comma
        pos = 0;
        while ((pos = line.find(delim)) != -1) {
            token = line.substr(0, pos);
            vec.push_back(stoi(token));
            line.erase(0, pos + delim.length());
        }
        vec.push_back(stoi(line));
    }
}

void solve() {
    // do first set
    for (int i : vec) {
        mp[i].push_back(idx);
        idx++;
        last = i;
    }

    for (int i = vec.size(); i < 30000000; i++) {
        if (mp[last].size() <= 1)
            last = 0;
        else
            last = mp[last][mp[last].size() - 1] - mp[last][mp[last].size() - 2];
        mp[last].push_back(idx);
        idx++;
    }
}

int main(void) {
    // time how long brute force takes (est ~1 min)
    auto start = std::chrono::high_resolution_clock::now();

    // read input
    readInput();

    // solve
    solve();

    // print answer
    cout << last << endl;

    // print time
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    // return
    return 0;
}