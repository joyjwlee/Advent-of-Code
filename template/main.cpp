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
    return 0;
}

int part_2() {
    return 0;
}
