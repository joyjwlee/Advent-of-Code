#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;
vector<string> vec;
vector<vector<char>> seats, after;
int width = 0, height = 0;

void readInput() {
    // read input while getting dimensions
    while (getline(file, line)) {
        vec.push_back(line);
        width = line.size();
        height++;
    }

    // increase for 0 padding
    width += 2, height += 2;
}

void initSeats() {
    // resize
    seats.resize(height);
    for (int i = 0; i < seats.size(); i++)
        seats[i].resize(width);

    // set all to floor
    for (int i = 0; i < seats.size(); i++)
        for (int j = 0; j < seats[i].size(); j++)
            seats[i][j] = '.';

    // set middle char
    for (int i = 1; i < seats.size() - 1; i++) {
        for (int j = 1; j < seats[i].size() - 1; j++) {
            seats[i][j] = vec[i - 1][j - 1];
        }
    }
}

int occupied(int i, int j) {
    int n = 0;
    for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
            // if not self and neighbor is also occupied
            if ((k != i || l != j) && seats[k][l] == '#') {
                n++;
            }
        }
    }
    return n;
}

bool areSame() {
    int diff = 0;
    for (int i = 0; i < seats.size(); i++)
        for (int j = 0; j < seats[i].size(); j++)
            if (seats[i][j] != after[i][j])
                diff++;
    return diff == 0;
}

void simulate() {
    // break when nonstatic
    while (true) {
        // reset after
        after = seats;

        // loop through all charsinside, update to "after"
        for (int i = 0; i < seats.size(); i++) {
            for (int j = 0; j < seats[i].size(); j++) {
                // if L and none
                if (seats[i][j] == 'L') {
                    if (occupied(i, j) == 0) {
                        after[i][j] = '#';
                    }
                }
                // if # and 4 or more
                else if (seats[i][j] == '#') {
                    if (occupied(i, j) >= 4) {
                        after[i][j] = 'L';
                    }
                }
                // otherwise .
                else
                    after[i][j] = '.';
            }
        }

        // break condition
        if (areSame())
            break;

        // update seats
        seats = after;
    }
}

int ans() {
    int n = 0;
    int diff = 0;
    for (int i = 0; i < seats.size(); i++)
        for (int j = 0; j < seats[i].size(); j++)
            if (seats[i][j] == '#')
                n++;
    return n;
}

int main(void) {
    // read input and sort
    readInput();

    // initialize seats vector
    initSeats();

    // simulate
    simulate();

    // print answer and exit
    cout << ans();
    return 0;
}