#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<pair<char, int>> actions;
int x = 0, y = 0, wx = 10, wy = 1, angle = 0, s = 0, c = 0, tx = 0, ty = 0;
char action;

void readInput() {
    // parse while reading
    while (getline(file, line)) {
        actions.push_back(make_pair(line[0], stoi(line.substr(1))));
    }
}

void solve() {
    for (pair<char, int> p : actions) {
        // get action
        action = p.first;

        // move waypoint
        if (action == 'N')
            wy += p.second;
        if (action == 'E')
            wx += p.second;
        if (action == 'S')
            wy -= p.second;
        if (action == 'W')
            wx -= p.second;

        // move ship
        if (action == 'F') {
            // move
            tx = (wx - x) * p.second;
            ty = (wy - y) * p.second;

            // move ship
            x += tx, y += ty;

            // move waypoint
            wx += tx, wy += ty;
        }

        // rotate waypoint
        if (action == 'R' || action == 'L') {
            // set angle and get trig vals
            angle = p.second;
            if (action == 'R')
                angle *= -1;
            s = sin(angle * M_PI / 180);
            c = cos(angle * M_PI / 180);

            // translate point back to origin
            wx -= x;
            wy -= y;

            // rotate point
            tx = wx * c - wy * s;
            ty = wx * s + wy * c;

            // translate point back
            wx = tx + x;
            wy = ty + y;
        }
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