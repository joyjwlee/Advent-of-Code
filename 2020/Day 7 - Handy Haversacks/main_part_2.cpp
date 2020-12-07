#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("test.txt");
string line, temp, outside, inside, curr;

// variables
map<string, vector<pair<string, int>>> hierarchy;
map<string, bool> visited;
int ans = 0, freq = 0, sum = 0;

int dfs(string curr, int num) {
    // edge case
    if (hierarchy[curr].size() == 0)
        return num;
    // otherwise dfs
    else {
        sum = 0;
        for (pair<string, int> p : hierarchy[curr]) {
            cout << p.first << " ";
            sum += dfs(p.first, p.second);
        }
        sum *= num;
        sum += num;
        cout << curr << " " << sum << " " << num << endl;
        return sum;
    }
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

    // print answer
    /*
    for (auto itr = hierarchy.begin(); itr != hierarchy.end(); itr++) {
        cout << itr->first << endl;
        for (int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i].first << " " << itr->second[i].second << "|| ";
        }
        cout << "\n\n";
    }
    */
    for (pair<string, int> p : hierarchy["shiny gold"]) {
        ans += dfs(p.first, p.second);
    }
    cout << ans;
    return 0;
}