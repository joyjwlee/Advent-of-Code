#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;

// method declarations
int init();
int part_1();
int part_2();

int main(void) {
    init();
    cout << part_1() << endl;
    cout << part_2() << endl;
    return 0;
}

int init() {
    // read input file, put into vector
    while (getline(file, line))
        vec.push_back(line);
    return 0;
}

int part_1() {
    int x = 0, y = 0;
    for (string s : vec) {
        int amt = stoi(s.substr(s.find(" ") + 1));
        if (s[0] == 'U')
            x += amt;
        if (s[0] == 'D')
            x -= amt;
        if (s[0] == 'L')
            y -= amt;
        if (s[0] == 'R')
            y += amt;
        cout << x << "\t" << y << endl;
    }
    return 0;
}

int part_2() {
    return 0;
}
