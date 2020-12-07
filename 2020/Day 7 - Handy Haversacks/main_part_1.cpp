#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // set up input
    ifstream file("input.txt");
    string line, temp, outside, inside, curr;

    // variables
    map<string, vector<string>> hierarchy;
    map<string, bool> visited;
    set<string> ans;

    while (getline(file, line)) {
        // skip if cannot contain
        size_t found = line.find("no other bags");
        if (found != string::npos)
            continue;

        // otherwise add to map
        else {
            // get outside and add to set
            outside = line.substr(0, line.find("bags") - 1);

            // split by space
            vector<string> tokens;
            stringstream delim(line);
            while (getline(delim, temp, ' ')) {
                tokens.push_back(temp);
            }

            // get inners, add to map, and add to set
            for (int i = 7; i < tokens.size(); i += 4) {
                inside = tokens[i - 2] + " " + tokens[i - 1];
                hierarchy[inside].push_back(outside);
            }
        }
    }

    // BFS
    queue<string> q;
    q.push("shiny gold");
    while (!q.empty()) {
        // get current
        curr = q.front();
        q.pop();

        // add if not visited yet
        if (!visited[curr]) {
            for (string s : hierarchy[curr]) {
                q.push(s);
                ans.insert(s);
            }
        }

        // mark as visited
        visited[curr] = true;
    }

    // print answer
    cout << ans.size();
    return 0;
}