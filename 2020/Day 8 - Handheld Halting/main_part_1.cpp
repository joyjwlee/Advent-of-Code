#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line, command, curr = "";
int ans = 0, val, idx = 0;
vector<pair<string, int>> commands;
map<int, bool> visited;

int main(void) {
    // read input
    while (getline(file, line)) {
        // extract info
        command = line.substr(0, 3);
        val = stoi(line.substr(5, line.size() - 5));
        if (line[4] == '-')
            val *= -1;
        // push to vector
        commands.push_back(make_pair(command, val));
    }

    // loop through
    curr = commands[0].first;
    while (true) {
        // break or mark as visited
        if (visited[idx])
            break;
        visited[idx] = true;

        // do diff scenarios
        if (curr == "acc") {
            ans += commands[idx].second;
            idx++;
        } else if (curr == "jmp") {
            idx += commands[idx].second;
        } else if (curr == "nop") {
            idx++;
        }

        // update current string
        curr = commands[idx].first;
    }

    // print answer and exit
    cout << ans;
    return 0;
}