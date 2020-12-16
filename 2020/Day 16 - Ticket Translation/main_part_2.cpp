#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
map<int, bool> fields;
int ans = 0, type = 0, a1, a2, b1, b2;
size_t pos, pos1, pos2;
string delim = ",", token, a, b;
vector<int> myTickets, nearbyTickets;

void readInput() {
    while (getline(file, line)) {
        // if 0, skip
        if (line.size() == 0)
            continue;

        // increment counter
        if (line == "your ticket:" || line == "nearby tickets:") {
            type++;
            continue;
        }

        // if type is 0, get fields
        if (type == 0) {
            // get the pairs
            pos1 = line.find(":") + 2;
            pos2 = line.find(" or");
            a = line.substr(pos1, pos2 - pos1);
            b = line.substr(pos2 + 4);

            // now split into ints and fill up map
            pos = a.find("-");
            a1 = stoi(a.substr(0, pos));
            a2 = stoi(a.substr(pos + 1));
            for (int i = a1; i <= a2; i++)
                fields[i] = true;

            pos = b.find("-");
            b1 = stoi(b.substr(0, pos));
            b2 = stoi(b.substr(pos + 1));
            for (int i = b1; i <= b2; i++)
                fields[i] = true;
        }

        // if type is 1, get my ticket
        if (type == 1) {
            // split by comma
            pos = 0;
            while ((pos = line.find(delim)) != -1) {
                token = line.substr(0, pos);
                myTickets.push_back(stoi(token));
                line.erase(0, pos + delim.length());
            }
            myTickets.push_back(stoi(line));
        }

        // if type is 2, get nearby tickets
        if (type == 2) {
            // split by comma
            pos = 0;
            while ((pos = line.find(delim)) != -1) {
                token = line.substr(0, pos);
                nearbyTickets.push_back(stoi(token));
                line.erase(0, pos + delim.length());
            }
            nearbyTickets.push_back(stoi(line));
        }
    }
}

void solve() {
    for (int n : nearbyTickets)
        if (!fields[n])
            ans += n;
}

int main(void) {
    // read input
    readInput();

    // solve
    solve();

    // print answer and return
    cout << ans;
    return 0;
}