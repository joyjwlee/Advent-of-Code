#include <bits/stdc++.h>

using namespace std;

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;

// method declarations
int init();
int part_1();
int part_2();
int priority(char c);

int main(void) {
    init();
    cout << part_1() << endl;
    cout << part_2() << endl;
    return 0;
}

int init() {
    // read input file, put into vector
    while (getline(file, line)) {
        vec.push_back(line);
    }
    return 0;
}

int part_1() {
    int totPrio = 0;
    for (string r : vec) {
        set<char> s;
        for (int i = 0; i < r.size() / 2; i++)
            s.insert(r[i]);
        for (int i = r.size() / 2; i < r.size(); i++) {
            if (s.find(r[i]) != s.end()) {
                totPrio += priority(r[i]);
                break;
            }
        }
    }
    return totPrio;
}

int part_2() {
    int totPrio = 0;
    for (int i = 0; i < vec.size(); i += 3) {
        string a = vec[i];
        string b = vec[i + 1];
        string c = vec[i + 2];
        for (char j = 'A'; j <= 'z'; j++)
            if (0 <= a.find(j) && a.find(j) < a.length())
                if (0 <= b.find(j) && b.find(j) < b.length())
                    if (0 <= c.find(j) && c.find(j) < c.length())
                        totPrio += priority(j);
    }
    return totPrio;
}

int priority(char c) {
    return islower(c) ? c - 'a' + 1 : c - 'A' + 27;
}