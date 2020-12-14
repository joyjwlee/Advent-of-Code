#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("test.txt");
string line;
vector<string> lines;
long long eta, idx = 0, pos;
vector<pair<int, int>> buses;

void readInput() {
    while (getline(file, line)) {
        lines.push_back(line);
    }

    // get eta
    eta = stoi(lines[0]);

    // parse buses
    idx = 0;
    string s = lines[1], delimiter = ",";
    while ((pos = s.find(delimiter)) != -1) {
        // if a bus
        if (s.substr(0, pos) != "x")
            buses.push_back(make_pair(stoi(s.substr(0, pos)), idx));
        s.erase(0, pos + delimiter.length());
        idx++;
    }
    if (s != "x")
        buses.push_back(make_pair(stoi(s), idx));
}

bool works() {
    for (pair<int, int> p : buses)
        if ((p.first - eta % p.first) % p.first != p.second)
            return false;
    return true;
}

void solve() {
    eta = 100000000000000;
    while (!works()) {
        eta++;
        cout << eta << endl;
    }
}

int main(void) {
    // read input and sort
    readInput();

    // for (pair<int, int> p : buses)
    // cout << p.first << " " << p.second << endl;
    solve();

    // print answer and return
    cout << eta;
    return 0;
}