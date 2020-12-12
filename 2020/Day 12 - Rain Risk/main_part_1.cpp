#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<pair<char, int>> actions;
int x = 0, y = 0, dir = 0;
char action;

void readInput() {
    // parse while reading
    while (getline(file, line)) {
        actions.push_back(make_pair(line[0], stoi(line.substr(1, line.size() - 1))));
    }
}

void solve() {
    for (pair<char, int> p : actions) {
        action = p.first;
        if (action == 'F') {
            if (dir % 360 == 0)
                action = 'E';
            if (dir % 360 == 90)
                action = 'N';
            if (dir % 360 == 180)
                action = 'W';
            if (dir % 360 == 270)
                action = 'S';
        }
        if (action == 'N')
            y += p.second;
        if (action == 'E')
            x += p.second;
        if (action == 'S')
            y -= p.second;
        if (action == 'W')
            x -= p.second;
        if (action == 'L')
            dir += p.second;
        if (action == 'R')
            dir -= p.second;
    }
}

int main(void) {
    // read input and sort
    readInput();

    for (pair<char, int> p : actions)
        cout << p.first << " " << p.second << endl;

    // solve
    solve();

    // print answer and return
    cout << x << " " << y << endl;
    cout << abs(x) + abs(y);
    return 0;
}