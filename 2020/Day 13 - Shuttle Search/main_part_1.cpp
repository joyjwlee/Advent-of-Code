#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<string> lines;
int eta, pos, minMins = 0x3f3f3f3f, bus;
vector<int> buses;

void readInput() {
    while (getline(file, line)) {
        lines.push_back(line);
    }

    // get eta
    eta = stoi(lines[0]);

    // parse buses
    string s = lines[1], delimiter = ",";
    while ((pos = s.find(delimiter)) != -1) {
        // if a bus
        if (s.substr(0, pos) != "x")
            buses.push_back(stoi(s.substr(0, pos)));
        s.erase(0, pos + delimiter.length());
    }
    if (s != "x")
        buses.push_back(stoi(s));
}

void solve() {
    // loop and update both
    for (int n : buses) {
        if (n - eta % n < minMins) {
            minMins = n - eta % n;
            bus = n;
        }
    }
}

int main(void) {
    // read input and sort
    readInput();

    // print answer and return
    cout << minMins * bus;
    return 0;
}