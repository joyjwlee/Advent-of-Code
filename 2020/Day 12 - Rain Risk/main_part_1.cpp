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
        actions.push_back(make_pair(line[0], stoi(line.substr(1))));
    }
}

void solve() {
    for (pair<char, int> p : actions) {
        // get direction
        action = p.first;
        if (action == 'F') {
            // make sure dir is positive
            dir = 360 + dir % 360;

            if (dir % 360 == 0)
                action = 'E';
            if (dir % 360 == 90)
                action = 'N';
            if (dir % 360 == 180)
                action = 'W';
            if (dir % 360 == 270)
                action = 'S';
        }

        // move
        if (action == 'N')
            y += p.second;
        if (action == 'E')
            x += p.second;
        if (action == 'S')
            y -= p.second;
        if (action == 'W')
            x -= p.second;

        // change dir
        if (action == 'R')
            dir -= p.second;
        if (action == 'L')
            dir += p.second;
    }
}

int main(void) {
    // read input and sort
    readInput();

    // solve
    solve();

    // print answer and return
    cout << abs(x) + abs(y);
    return 0;
}