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
int score(char a, char b);

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
    // O(n) solve
    int totScore = 0;
    for (string s : vec) {
        char me = 'A';
        if (s[2] == 'Y') me = 'B';
        if (s[2] == 'Z') me = 'C';
        totScore += score(s[0], me);
    }
    return totScore;
}

// returns score for rock paper scissors
// a is opponent, b is me
int score(char a, char b) {
    if (a == 'A' && b == 'A') return 1 + 3;
    if (a == 'A' && b == 'B') return 2 + 6;
    if (a == 'A' && b == 'C') return 3 + 0;
    if (a == 'B' && b == 'A') return 1 + 0;
    if (a == 'B' && b == 'B') return 2 + 3;
    if (a == 'B' && b == 'C') return 3 + 6;
    if (a == 'C' && b == 'A') return 1 + 6;
    if (a == 'C' && b == 'B') return 2 + 0;
    if (a == 'C' && b == 'C') return 3 + 3;
    return -1;
}

int part_2() {
    // O(n) solve
    int totScore = 0;
    for (string s : vec) {
        if (s[2] == 'X') {
            totScore += 0;
            if (s[0] == 'A') totScore += 3;
            if (s[0] == 'B') totScore += 1;
            if (s[0] == 'C') totScore += 2;
        }
        if (s[2] == 'Y') {
            totScore += 3;
            if (s[0] == 'A') totScore += 1;
            if (s[0] == 'B') totScore += 2;
            if (s[0] == 'C') totScore += 3;
        }
        if (s[2] == 'Z') {
            totScore += 6;
            if (s[0] == 'A') totScore += 2;
            if (s[0] == 'B') totScore += 3;
            if (s[0] == 'C') totScore += 1;
        }
    }
    return totScore;
}
