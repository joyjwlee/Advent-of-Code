#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line, temp, outside, inside, curr;

// variables
map<string, vector<pair<string, int>>> hierarchy;
map<string, bool> visited;
int ans = 0, freq = 0, sum = 0;

int dfs(string curr, int num) {
    int sum = 0;
    // dfs the sub-baggages
    for (pair<string, int> p : hierarchy[curr]) {
        sum += dfs(p.first, p.second);
    }
    sum *= num;
    sum += num;
    return sum;
}

int main(void) {
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
                freq = stoi(tokens[i - 3]);
                // flip from part 1
                hierarchy[outside].push_back(make_pair(inside, freq));
            }
        }
    }

    // loop through and add to ans
    for (pair<string, int> p : hierarchy["shiny gold"]) {
        ans += dfs(p.first, p.second);
    }

    // print and exit
    cout << ans;
    return 0;
}