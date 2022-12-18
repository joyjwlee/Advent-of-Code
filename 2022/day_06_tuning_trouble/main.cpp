#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;
string str;

// method declarations
int init();
int part_1();
int part_2();
void printCrates();
bool allUnique(string s);

// use 0-based indexing for everything
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
    str = vec[0];
    for (int i = 4; i < str.size(); i++)
        if (allUnique(str.substr(i - 4, 4)))
            return i;
    return 0;
}

bool allUnique(string s) {
    int checker = 0;
    for (char c : s) {
        int bit = c - 'a';
        if ((checker & (1 << bit)) > 0)
            return false;
        checker = checker | (1 << bit);
    }
    return true;
}

int part_2() {
    str = vec[0];
    for (int i = 14; i < str.size(); i++)
        if (allUnique(str.substr(i - 14, 14)))
            return i;
    return 0;
}
