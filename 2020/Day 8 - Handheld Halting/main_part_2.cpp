#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line, command, curr = "";
int ans = 0, val, idx = 0;
vector<pair<string, int>> commands;
map<int, bool> visited;

void readInput() {
    while (getline(file, line)) {
        // extract info
        command = line.substr(0, 3);
        val = stoi(line.substr(5, line.size() - 5));
        if (line[4] == '-')
            val *= -1;
        // push to vector
        commands.push_back(make_pair(command, val));
    }
}

void solve() {
    idx = 0;
    curr = commands[0].first;
    while (idx != commands.size() - 1) {
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

    // do last one as well
    if (curr == "acc")
        ans += commands[idx].second;
}

bool notLoopy() {
    map<int, bool> visited;
    idx = 0;
    curr = commands[0].first;
    while (true) {
        // if last, return true
        if (idx == commands.size() - 1)
            return true;

        // break or mark as visited
        if (visited[idx])
            break;
        visited[idx] = true;

        // do diff scenarios
        if (curr == "jmp")
            idx += commands[idx].second;
        else
            idx++;

        // update values
        curr = commands[idx].first;
    }
    // otherwise we've looped around
    return false;
}

void makeNonLoopy() {
    for (int i = 0; i < commands.size(); i++) {
        // if acc, continue
        if (commands[i].first == "acc")
            continue;
        // otherwise flip the other two and do
        else if (commands[i].first == "jmp") {
            commands[i].first = "nop";
            // if not loopy, break
            if (notLoopy())
                return;
            // otherwise put it back
            commands[i].first = "jmp";
        } else if (commands[i].first == "nop") {
            commands[i].first = "jmp";
            // if not loopy, break
            if (notLoopy())
                return;
            // otherwise put it back
            commands[i].first = "nop";
        }
    }
}

int main(void) {
    // read input
    readInput();

    // find where it is loopy and fix
    makeNonLoopy();

    // solve
    solve();

    // print answer and exit
    cout << ans;
    return 0;
}